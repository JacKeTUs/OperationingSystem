#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/slab.h>
#include <linux/keyboard.h>
#include <linux/notifier.h>
#include <linux/time.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/fs_struct.h>
#include <linux/uaccess.h>

#define ROLLOVER_KEYS 6
//#define DEBUG_VER 


#define DRIVER_VERSION "v1.1"
#define DRIVER_AUTHOR "Makarenko Oleg <jktu2308@gmail.com>"
#define DRIVER_DESC "Kernel module for behavior-recognition"

MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_LICENSE("GPL");

static int cur_rollover;
static int cur_rollover_idx;
static unsigned char previous_scancode;
char *msg;
bool opened;
struct proc_dir_entry *proc_file;
unsigned long time_for_search;
static unsigned counter = 0;
static irqreturn_t irq_handler(int irq, void *dev_id);
static void workqueue_function(struct work_struct *work);

static struct workqueue_struct *queue = NULL;

unsigned long mtime(void) {

	struct timespec t;
	getnstimeofday(&t);
	unsigned long mt = (unsigned long)((t.tv_sec % 100000) * 1000 + t.tv_nsec / 1000000);
	return mt;
}


struct rollover_tbl {

	int rollover_code;
	unsigned long downtime;
	unsigned long time_for_search;
	struct rollover_tbl *next;
} *rollover_table;


struct log_queue {

	struct rollover_tbl *frnt, *rear;
} *log_table;


void init_queue(struct log_queue *q) {

	q->frnt = NULL;
	q->rear = NULL;
}

int queue_isempty(struct log_queue *q) {

	if (q->frnt == NULL) {
		q->rear = NULL;
		    return 1;
	}  else 
		return 0;
}

void insert_in_queue(struct log_queue *q, int code, unsigned long time, unsigned long time_up) {

	if((q->rear == NULL) && (q->frnt == NULL)) {
    		q->rear = kmalloc(sizeof(struct rollover_tbl), GFP_ATOMIC);
		q->rear->rollover_code = code;
		q->rear->downtime = time;
		q->rear->time_for_search = time_up;
		q->rear->next = NULL;
    		q->frnt = q->rear;
  	} else {
		struct rollover_tbl* temp = kmalloc(sizeof(struct rollover_tbl), GFP_ATOMIC);
		q->rear->next = temp;
    		temp->rollover_code = code;
		temp->downtime = time;
		temp->time_for_search = time_up;
		temp->next = NULL;
		q->rear = temp;
	}
}

struct rollover_tbl remove_from_queue(struct log_queue *q) {

	struct rollover_tbl ret;
	struct rollover_tbl *temp;
	ret.rollover_code = -1;
	ret.downtime = 0;
	ret.time_for_search = 0;

	if(queue_isempty(q)) {
		return ret;
	}
	ret.rollover_code = q->frnt->rollover_code;
	ret.downtime = q->frnt->downtime;
	ret.time_for_search = q->frnt->time_for_search;

	temp = q->frnt;
	q->frnt = q->frnt->next;
	kfree(temp);

	return ret;
}

static int find_key_rt(struct rollover_tbl *rt, int key) {
	int i, ret_idx = -1;
	for(i = 0; i < ROLLOVER_KEYS; i++) 
		if (rt[i].rollover_code == key) {
			ret_idx = i;
			break;
		}
	return ret_idx;
}

static irqreturn_t irq_handler(int irq, void *dev_id) {
	struct work_struct *work = (struct work_struct*)kmalloc(sizeof(struct work_struct), GFP_KERNEL);
      	if(work) {
         	INIT_WORK(work, workqueue_function);
		queue_work(queue, work);
      	} else {
		printk(KERN_ERR "keylogin: Could not allocate memory for work.\n");
	}

	return IRQ_HANDLED;
}

static void workqueue_function(struct work_struct *work)
{
	unsigned char scancode = inb(0x60);
	if (scancode != previous_scancode) {
		if (scancode & 0x80) {
			scancode -= 128;
			if (cur_rollover != 0) {
				unsigned long tmp;
				tmp = mtime();
				// Ищем пустую ячейку
				cur_rollover_idx = find_key_rt(rollover_table, scancode);
				if (cur_rollover_idx != -1) {
					// Нашли пустую ячейку
					cur_rollover--;
					tmp = (tmp - rollover_table[cur_rollover_idx].downtime);


					insert_in_queue(log_table, scancode, tmp, rollover_table[cur_rollover_idx].time_for_search);

					rollover_table[cur_rollover_idx].rollover_code = -1;	
					rollover_table[cur_rollover_idx].downtime = 0;
				}
				
			}
		}
		 else {
			if (cur_rollover < ROLLOVER_KEYS) {	
				unsigned long tmp;
				tmp = mtime();	

				// Ищем пустую ячейку
				cur_rollover_idx = find_key_rt(rollover_table, -1);
				if (cur_rollover_idx != -1) {
					// Нашли пустую ячейку
					rollover_table[cur_rollover_idx].rollover_code = scancode;
					// Записали время, в которое клавиша была нажата
					rollover_table[cur_rollover_idx].downtime = mtime();
					
					// Записали время на поиск клавиши
					rollover_table[cur_rollover_idx].time_for_search = tmp - time_for_search;
					
					cur_rollover++;
					time_for_search = mtime(); // запуск таймера на новый поиск клавиши
				}
					
			}
		}
		
		previous_scancode = scancode;
	}
	kfree((void*)work);
}


static int procfile_open(struct inode *i, struct file *f) {
	opened = true;
	return 0;
}

static ssize_t procfile_read(struct file *filp, char *buffer, size_t count, loff_t *offp) {	
	
	int len = 0;
	if (queue_isempty(log_table)) return 0;
	struct rollover_tbl temp = remove_from_queue(log_table);
	//struct rollover_tbl temp = pop_log();
	//if (temp.rollover_code == -1) return 0;
		
	len += sprintf(msg, "%i %lu %lu\n", temp.rollover_code, temp.downtime, temp.time_for_search);

	copy_to_user(buffer, msg, len);

	opened = false;
	return len;
}

const struct file_operations proc_file_fops = {
	.open = procfile_open,
	.read = procfile_read,
};

static int keylogin_init(void)
{
	msg = kmalloc(50*sizeof(char), GFP_ATOMIC);
	rollover_table	= kmalloc(ROLLOVER_KEYS * sizeof(struct rollover_tbl), GFP_ATOMIC);
	log_table = kmalloc(sizeof(struct log_queue), GFP_ATOMIC);
	init_queue(log_table);
	time_for_search = 0;
	int i;
	for (i = 0; i < ROLLOVER_KEYS; i++) {
		rollover_table[i].rollover_code = -1;	
		rollover_table[i].downtime = 0;	
		rollover_table[i].next = NULL;
	}
	cur_rollover = 0;
	cur_rollover_idx = 0;
	
	proc_file = proc_create("keylogin", 0644, NULL, &proc_file_fops);
	if (proc_file == NULL) {
		remove_proc_entry("keylogin", NULL);
		printk(KERN_ERR "keylogin: Can't create proc file\n");
		return -ENOMEM;
	}

	//free_irq(1, NULL);
	int result = request_irq(1, (irq_handler_t) irq_handler, IRQF_SHARED, "keylogin_rirq", (void*)(irq_handler));
	if (!result) {
		queue = alloc_workqueue("keylogin_wq", WQ_MEM_RECLAIM | WQ_HIGHPRI, 0);
		if (!queue) {
			free_irq(1, (void*)irq_handler);
			printk(KERN_ERR "keylogin: Could not allocate memory for queue.\n");

			return -ENOMEM;
		}
	}	
	printk(KERN_INFO "keylogin loaded!");	

	return 0;
}

static void keylogin_init_release(void)
{	
	remove_proc_entry("keylogin", NULL);

	kfree(rollover_table);	
	kfree(msg);

	/*while (!queue_isempty(log_table)) {
		remove_from_queue(log_table);
	}
	kfree(log_table);*/
	
	free_irq(1, (void*)irq_handler);
	flush_workqueue(queue);
	destroy_workqueue(queue);
	printk(KERN_INFO "keylogin unloaded!");
}

module_init(keylogin_init);
module_exit(keylogin_init_release);
