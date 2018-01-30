#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QTextStream"
#include "math.h"
#include <QMessageBox>

#define PROC_FILE "/proc/keylogin"
#define USER_FILE "USERS"

#define ABS(x) (((x) >= 0) ? (x) : (-(x)))

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    userUnknown = new User("User Unknown");
    load_users();

    ui->tableWidget->setColumnCount(3);

    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Код символа"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Время нажатия символа"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Время поиска символа"));
    ui->tableWidget->horizontalHeader()->stretchLastSection();
    ui->tableWidget->horizontalHeader()->adjustSize();
    this->updateUserInfo(userList.at(0));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QFile file(PROC_FILE);
    int key;
    int downtime, uptime;
    if (file.exists() && file.open(QIODevice::ReadOnly))
    {
       QTextStream stream(&file);
       QString line;

       do
        {
          line = stream.readLine();
          if (!line.isEmpty()) {
                key = line.section(" ", 0, 0).trimmed().toInt();
                downtime = line.section(" ", 1, 1).trimmed().toInt();
                uptime = line.section(" ", 2, 2).trimmed().toInt();
                ui->textEdit->append(QString("Key: " + QString::number(key) + " downtime: " + QString::number(downtime) + " time for search: " + QString::number(uptime) +"\n"));
          }
        }
       while (!line.isNull());
    }

    file.close();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit->clear();
}

/*!
 * \brief MainWindow::on_pushButton_3_clicked
 * Конец отслеживания - чтение из proc/keylogger
 * Подсчёт значений
 */
void MainWindow::on_pushButton_3_clicked()
{
    if (ui->checkBox->isChecked() && (ui->text_edit->toPlainText() != ui->lineEdit->text())) {
        QMessageBox::warning(this, tr("Ошибка!"),
                                       tr("Текст не соответствует заданию!"));
        return;
    }


    QFile file(PROC_FILE);
    QList<keys_time*> kt;
    int key;
    int downtime, uptime;
    if (file.exists() && file.open(QIODevice::ReadOnly))
    {
       QTextStream stream(&file);
       QString line;

       do
        {
          line = stream.readLine();
          if (!line.isEmpty()) {
                key = line.section(" ", 0, 0).trimmed().toInt();
                downtime = line.section(" ", 1, 1).trimmed().toInt();
                uptime = line.section(" ", 2, 2).trimmed().toInt();
                kt.append(new keys_time(key, downtime, uptime));
          }
        }
       while (!line.isNull());
    }

    file.close();

    userUnknown->clearKeysList();
    userUnknown->mergeKeysList(kt);

    ui->userNameEdit->setText(userUnknown->getUsername());
    ui->key_delay->setText(QString::number(userUnknown->getMidDelay()));
    ui->key_search->setText(QString::number(userUnknown->getMidSearch()));

    User* u = findUserByKeys(kt);
    if (u) {
        ui->userNameEdit_3->setText(u->getUsername());
        ui->key_delay_3->setText(QString::number(u->getMidDelay()));
        ui->key_search_3->setText(QString::number(u->getMidSearch()));
        QMessageBox::warning(this, tr("Уведомление"),
                                       tr("Значения посчитаны!"));
    } else {
        QMessageBox::warning(this, tr("Уведомление"),
                                       tr("Недостаточно данных для идентификации!"));
    }

}

/*!
 * \brief MainWindow::on_pushButton_5_clicked
 * Начало отслеживания - очистка файла proc/keylogger
 */
void MainWindow::on_pushButton_5_clicked()
{
    QFile file(PROC_FILE);
    if (file.exists() && file.open(QIODevice::ReadOnly))
    {
       QTextStream stream(&file);
       QString line;

       do
        {
          line = stream.readLine();
        }
       while (!line.isNull());
    }

    file.close();
    ui->text_edit->clear();
    QMessageBox::warning(this, tr("Уведомление"),
                                   tr("Отслеживание начато!"));

}



/*!
 * \brief MainWindow::load_users
 * Функция загрузки пользователей в программу
 */
void MainWindow::load_users() {
    userList.clear();
    ui->comboBox->clear();
    QFile file(USER_FILE);
    if (file.exists() && file.open(QIODevice::ReadOnly))
    {
       QTextStream stream(&file);
       QString line;

       do
        {
          line = stream.readLine();
          if (!line.isEmpty()) {
              userList.append(new User(line));
              ui->comboBox->addItem(line);
          }
        }
       while (!line.isNull());
    }

    file.close();
}

/*!
 * \brief MainWindow::on_pushButton_4_clicked
 * Сохранение нового пользователя
 */
void MainWindow::on_pushButton_4_clicked()
{
    if (ui->userNameEdit->text().isEmpty()) {
        QMessageBox::warning(this, tr("Ошибка!"),
                                       tr("Имя не должно быть пустое!"));
        return;
    }

    for (int i = 0; i < userList.length(); i++) {
        if (userList.at(i)->getUsername() == ui->userNameEdit->text()) {
            QMessageBox::warning(this, tr("Ошибка!"),
                                           tr("Пользователь уже существует!\n"
                                              "Его данные будут дополнены!"));

            userList.at(i)->mergeKeysList(userUnknown->getKeysList());
            userList.at(i)->updateFile();
            //updateUserInfo(userList.at(i));
            load_users();
            return;
        }
    }
    userUnknown->setUsername(ui->userNameEdit->text());
    userList.append(userUnknown);
    QFile(USER_FILE).remove();
    QFile file(USER_FILE);
    if (file.open(QIODevice::WriteOnly))
    {
       QTextStream stream(&file);
       QString line;

       for (int i = 0; i < userList.length(); i++) {
        stream << userList.at(i)->getUsername() << endl;
        userList.at(i)->updateFile();
       }
    }
    file.close();
    load_users();
    QMessageBox::warning(this, tr("Уведомление"),
                                   tr("Пользователь успешно сохранён!"));
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if (userList.isEmpty())
        return;
    User* u = userList.at(index);
    updateUserInfo(u);
}

User* MainWindow::findUserByKeys(QList<keys_time*> kt) {
    int r_ideal = 0;
    User* resultUser = NULL;
    bool notEnoughData = false;

    // Проходим по всем пользователям
    for (int i = 0; i < userList.length(); i++) {

        int DeltaPush = 0;
        int DeltaSearch = 0;

        // Проходим по всем отмеченным в kt клавишам и сверяемся
        for (int j = 0; j < kt.length(); j++) {
            keys_time *user_kt = userList.at(i)->getKeyInfo(kt.at(j)->get_keycode());

            if (user_kt->get_key_delay_time() == -1) {
                notEnoughData = true;
                break;
            }

            DeltaPush += ABS(user_kt->get_key_delay_time() - kt.at(j)->get_key_delay_time());
            DeltaSearch += ABS(user_kt->get_key_search_time() - kt.at(j)->get_key_search_time());
        }
        if (notEnoughData)
            continue;

        if (i == 0) {
            r_ideal = sqrt(pow(DeltaPush, 2) + pow(DeltaSearch, 2));
            resultUser = userList.at(i);
            continue;
        }

        // Расстояние "до идеала"
        float r = 0;
        r = sqrt(pow(DeltaPush, 2) + pow(DeltaSearch, 2));

        if (r < r_ideal) {
            r_ideal = r;
            resultUser = userList.at(i);
        }
    }
    return resultUser;
}

void MainWindow::on_pushButton_6_clicked()
{
    if (ui->pushButton_6->text() != "Сохранить текст") {
        ui->pushButton_6->setText("Сохранить текст");
        ui->lineEdit->setReadOnly(false);
    } else {
        ui->pushButton_6->setText("Изменить текст");
        ui->lineEdit->setReadOnly(true);
    }
}

void MainWindow::updateUserInfo(User *user) {

    ui->userNameEdit_2->setText(user->getUsername());
    ui->key_delay_2->setText(QString::number(user->getMidDelay()));
    ui->key_search_2->setText(QString::number(user->getMidSearch()));
    ui->progressBar->setValue((user->getKeysList().length() / 50.0)*100);

    ui->tableWidget->setRowCount(user->getKeysList().length());
    for (int i = 0; i < user->getKeysList().length(); i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(user->getKeysList().at(i)->get_keycode())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(user->getKeysList().at(i)->get_key_delay_time()) + " мс."));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(user->getKeysList().at(i)->get_key_search_time())+ " мс."));
    }
    ui->tableWidget->repaint();
}
