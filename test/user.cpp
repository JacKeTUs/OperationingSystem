#include "user.h"

/*!
 * \brief User::User
 */
User::User(QString userName)
{
    username = userName;
    QFile file(userName + "_keys");
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
                //i->textEdit->append(QString("Key: " + QString::number(key) + " downtime: " + QString::number(downtime) + " time for search: " + QString::number(uptime) +"\n"));
                keys_time* kt = new keys_time(key, downtime, uptime);
                userKeys.append(kt);
          }
        }
       while (!line.isNull());
    }

    file.close();
}

keys_time* User::getKeyInfo(int keycode) {
    for (int i = 0; i < userKeys.length(); i++) {
        if (userKeys.at(i)->get_keycode() == keycode)
            return userKeys.at(i);
    }
    return new keys_time(keycode, -1,-1);
}

QList<keys_time*> User::getKeysList() {
    return userKeys;
}

void User::updateFile() {
    QFile(username + "_keys").remove();
    QFile file(username + "_keys");
    if (file.open(QIODevice::WriteOnly))
    {
       QTextStream stream(&file);
       QString line;

       for (int i = 0; i < userKeys.length(); i++) {
           stream << userKeys.at(i)->get_info() << endl;
       }
    }
    file.close();
}

void User::mergeKeysList(QList<keys_time*> newData) {
    int idx = 0;
    bool found;
    while (newData.length() > 0) {
        found = false;
        for (int i = 0; i < userKeys.length(); i++) {
            if (userKeys.at(i)->get_keycode() == newData.at(idx)->get_keycode()) {
                found = true;
                userKeys.at(i)->add_key_delay_time(newData.at(idx)->get_key_delay_time());
                userKeys.at(i)->add_key_search_time(newData.at(idx)->get_key_search_time());
                break;
            }
        }
        if (!found) {
            userKeys.append(newData.at(idx));
        }
        newData.removeAt(idx);
    }
}

int User::getMidDelay() {
    if (userKeys.length() == 0)
        return -1;
    int sumTime;
    for (int i = 0; i < userKeys.length(); i++) {
        sumTime = userKeys.at(i)->get_key_delay_time();
    }
    return sumTime / userKeys.length();
}


int User::getMidSearch() {
    if (userKeys.length() == 0)
        return -1;
    int sumTime;
    for (int i = 0; i < userKeys.length(); i++) {
        sumTime = userKeys.at(i)->get_key_search_time();
    }
    return sumTime / userKeys.length();
}

QString User::getUsername() {
    return username;
}

void User::clearKeysList() {
    userKeys.clear();
}
