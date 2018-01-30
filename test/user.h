#ifndef USER_H
#define USER_H
#include "QString"
#include "QFile"
#include "QTextStream"

class keys_time
{
public:
    keys_time(int kc, int kd, int ks) { keycode = kc; key_delay_time = kd; key_search_time = ks;}
    int get_keycode() { return keycode; }
    int get_key_delay_time() { return key_delay_time; }
    int get_key_search_time() { return key_search_time; }
    QString get_info() { return QString::number(keycode) + " " + QString::number(key_delay_time) + " " +QString::number(key_search_time); }
    void add_key_delay_time(int newKD) { key_delay_time = (key_delay_time + newKD) / 2;}
    void add_key_search_time(int newKS) { key_search_time = (key_search_time + newKS) / 2;}

private:
    int keycode;
    int key_delay_time;
    int key_search_time;
};

class User
{
public:
    User(QString userName);

    keys_time *getKeyInfo(int keycode);
    void mergeKeysList(QList<keys_time *> newData);
    void clearKeysList();
    void updateFile();

    int getMidDelay();
    int getMidSearch();
    QString getUsername();
    void setUsername(QString un) {this->username = un;}
    QList<keys_time*> getKeysList();

private:
    QList<keys_time*> userKeys;
    QString username;

};

#endif // USER_H
