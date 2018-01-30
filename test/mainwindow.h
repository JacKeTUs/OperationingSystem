#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <user.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    QList<User*> userList;
    void load_users();
    User* userUnknown;
    User* findUserByKeys(QList<keys_time*> kt);
    void updateUserInfo(User* user);
};

#endif // MAINWINDOW_H
