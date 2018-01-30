/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    QLabel *key_delay_2;
    QLineEdit *userNameEdit_2;
    QLabel *label_6;
    QLabel *key_search_2;
    QLabel *label_7;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_2;
    QComboBox *comboBox;
    QLabel *label_11;
    QLabel *label_12;
    QTableWidget *tableWidget;
    QSpacerItem *horizontalSpacer;
    QProgressBar *progressBar;
    QWidget *tab_2;
    QGridLayout *gridLayout;
    QTextEdit *text_edit;
    QLabel *label;
    QPushButton *pushButton_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QLabel *key_search;
    QLabel *label_2;
    QLineEdit *userNameEdit;
    QLabel *key_delay;
    QLabel *label_4;
    QLabel *label_3;
    QPushButton *pushButton_4;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QLabel *key_delay_3;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_8;
    QLabel *label_10;
    QLineEdit *userNameEdit_3;
    QLabel *key_search_3;
    QLabel *label_9;
    QCheckBox *checkBox;
    QPushButton *pushButton_5;
    QLineEdit *lineEdit;
    QPushButton *pushButton_6;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QTextEdit *textEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1013, 512);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_6 = new QGridLayout(tab_3);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        groupBox_2 = new QGroupBox(tab_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        key_delay_2 = new QLabel(groupBox_2);
        key_delay_2->setObjectName(QStringLiteral("key_delay_2"));

        gridLayout_5->addWidget(key_delay_2, 1, 1, 1, 1);

        userNameEdit_2 = new QLineEdit(groupBox_2);
        userNameEdit_2->setObjectName(QStringLiteral("userNameEdit_2"));

        gridLayout_5->addWidget(userNameEdit_2, 0, 1, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_6, 2, 0, 1, 1);

        key_search_2 = new QLabel(groupBox_2);
        key_search_2->setObjectName(QStringLiteral("key_search_2"));

        gridLayout_5->addWidget(key_search_2, 2, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_7, 0, 0, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_5, 1, 0, 1, 1);


        gridLayout_6->addWidget(groupBox_2, 1, 0, 1, 3);

        verticalSpacer_2 = new QSpacerItem(20, 92, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_2, 5, 2, 1, 1);

        comboBox = new QComboBox(tab_3);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout_6->addWidget(comboBox, 0, 0, 1, 3);

        label_11 = new QLabel(tab_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_6->addWidget(label_11, 2, 0, 1, 1);

        label_12 = new QLabel(tab_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_6->addWidget(label_12, 4, 0, 1, 1);

        tableWidget = new QTableWidget(tab_3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout_6->addWidget(tableWidget, 5, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 5, 1, 1, 1);

        progressBar = new QProgressBar(tab_3);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        gridLayout_6->addWidget(progressBar, 3, 0, 1, 2);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout = new QGridLayout(tab_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        text_edit = new QTextEdit(tab_2);
        text_edit->setObjectName(QStringLiteral("text_edit"));

        gridLayout->addWidget(text_edit, 3, 0, 1, 3);

        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 5, 2, 1, 1);

        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        key_search = new QLabel(groupBox);
        key_search->setObjectName(QStringLiteral("key_search"));

        gridLayout_3->addWidget(key_search, 2, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        userNameEdit = new QLineEdit(groupBox);
        userNameEdit->setObjectName(QStringLiteral("userNameEdit"));

        gridLayout_3->addWidget(userNameEdit, 0, 1, 1, 1);

        key_delay = new QLabel(groupBox);
        key_delay->setObjectName(QStringLiteral("key_delay"));

        gridLayout_3->addWidget(key_delay, 1, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_3, 2, 0, 1, 1);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout_3->addWidget(pushButton_4, 4, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 3, 0, 1, 1);


        gridLayout->addWidget(groupBox, 6, 0, 1, 2);

        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        key_delay_3 = new QLabel(groupBox_3);
        key_delay_3->setObjectName(QStringLiteral("key_delay_3"));

        gridLayout_4->addWidget(key_delay_3, 1, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 3, 0, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_8, 1, 0, 1, 1);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_10, 2, 0, 1, 1);

        userNameEdit_3 = new QLineEdit(groupBox_3);
        userNameEdit_3->setObjectName(QStringLiteral("userNameEdit_3"));

        gridLayout_4->addWidget(userNameEdit_3, 0, 1, 1, 1);

        key_search_3 = new QLabel(groupBox_3);
        key_search_3->setObjectName(QStringLiteral("key_search_3"));

        gridLayout_4->addWidget(key_search_3, 2, 1, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_9, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_3, 6, 2, 1, 1);

        checkBox = new QCheckBox(tab_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 4, 0, 1, 1);

        pushButton_5 = new QPushButton(tab_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 5, 0, 1, 2);

        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setReadOnly(true);

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        pushButton_6 = new QPushButton(tab_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 1, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 1, 1, 1, 3);

        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_2->addWidget(pushButton, 1, 4, 1, 1);

        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setReadOnly(true);

        gridLayout_2->addWidget(textEdit, 0, 1, 1, 4);

        tabWidget->addTab(tab, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\230\320\264\320\265\320\275\321\202\320\270\321\204\320\270\320\272\320\260\321\206\320\270\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217 \320\277\320\276 \320\265\320\263\320\276 \320\274\320\260\320\275\320\265\321\200\320\265 \320\275\320\260\320\261\320\276\321\200\320\260 \321\202\320\265\320\272\321\201\321\202\320\260", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\265", Q_NULLPTR));
        key_delay_2->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\275\320\265\320\265 \320\262\321\200\320\265\320\274\321\217 \320\277\320\276\320\270\321\201\320\272\320\260 \320\272\320\273\320\260\320\262\320\270\321\210\320\270", Q_NULLPTR));
        key_search_2->setText(QString());
        label_7->setText(QApplication::translate("MainWindow", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\275\320\265\320\265 \320\262\321\200\320\265\320\274\321\217 \320\267\320\260\320\264\320\265\321\200\320\266\320\272\320\270 \320\272\320\273\320\260\320\262\320\270\321\210\320\270", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\321\204\320\270\320\273\321\214 \320\267\320\260\320\277\320\276\320\273\320\275\320\265\320\275 \320\275\320\260:", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\262\320\262\320\276\320\264\320\270\320\274\321\213\321\205 \321\201\320\270\320\274\320\262\320\276\320\273\320\260\321\205:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\270", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\202\320\265\320\272\321\201\321\202:", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\236\321\206\320\265\320\275\320\270\321\202\321\214", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\222\320\260\321\210\320\270 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213", Q_NULLPTR));
        key_search->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "\320\222\320\260\321\210\320\265 \321\201\321\200\320\265\320\264\320\275\320\265\320\265 \320\262\321\200\320\265\320\274\321\217 \320\267\320\260\320\264\320\265\321\200\320\266\320\272\320\270 \320\272\320\273\320\260\320\262\320\270\321\210\320\270", Q_NULLPTR));
        key_delay->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\320\222\320\260\321\210\320\265 \321\201\321\200\320\265\320\264\320\275\320\265\320\265 \320\262\321\200\320\265\320\274\321\217 \320\277\320\276\320\270\321\201\320\272\320\260 \320\272\320\273\320\260\320\262\320\270\321\210\320\270", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213 \320\276\321\206\320\265\320\275\320\270\320\262\320\260\320\275\320\270\321\217", Q_NULLPTR));
        key_delay_3->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\275\320\265\320\265 \320\262\321\200\320\265\320\274\321\217 \320\267\320\260\320\264\320\265\321\200\320\266\320\272\320\270 \320\272\320\273\320\260\320\262\320\270\321\210\320\270", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\275\320\265\320\265 \320\262\321\200\320\265\320\274\321\217 \320\277\320\276\320\270\321\201\320\272\320\260 \320\272\320\273\320\260\320\262\320\270\321\210\320\270", Q_NULLPTR));
        key_search_3->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow", "\320\241\321\202\321\200\320\276\320\263\320\270\320\271 \321\200\320\265\320\266\320\270\320\274", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\276\321\202\321\201\320\273\320\265\320\266\320\270\320\262\320\260\320\275\320\270\320\265", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("MainWindow", "\320\227\320\264\321\200\320\260\320\262\321\201\321\202\320\262\321\203\320\271\321\202\320\265, \320\272\320\260\320\272 \321\203 \320\262\320\260\321\201 \320\264\320\265\320\273\320\260?", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\202\320\265\320\272\321\201\321\202", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\320\230\320\264\320\265\320\275\321\202\320\270\321\204\320\270\320\272\320\260\321\206\320\270\321\217", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\233\320\276\320\263\320\263\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\275\320\260\320\266\320\260\321\202\320\270\320\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
