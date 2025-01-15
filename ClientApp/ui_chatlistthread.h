/********************************************************************************
** Form generated from reading UI file 'chatlistthread.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATLISTTHREAD_H
#define UI_CHATLISTTHREAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatList
{
public:
    QLabel *label;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_3;
    QListWidget *listWidget;

    void setupUi(QWidget *ChatList)
    {
        if (ChatList->objectName().isEmpty())
            ChatList->setObjectName(QString::fromUtf8("ChatList"));
        ChatList->resize(800, 600);
        label = new QLabel(ChatList);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(320, 10, 151, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        pushButton_3 = new QPushButton(ChatList);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(599, 110, 101, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setWeight(50);
        pushButton_3->setFont(font1);
        lineEdit_3 = new QLineEdit(ChatList);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(100, 110, 471, 51));
        listWidget = new QListWidget(ChatList);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu"));
        font2.setPointSize(22);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setFont(font2);
        QFont font3;
        font3.setPointSize(24);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setFont(font3);
        QFont font4;
        font4.setFamily(QString::fromUtf8("Ubuntu"));
        font4.setPointSize(20);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget);
        __qlistwidgetitem2->setFont(font4);
        QFont font5;
        font5.setPointSize(20);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(listWidget);
        __qlistwidgetitem3->setFont(font5);
        QFont font6;
        font6.setPointSize(19);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(listWidget);
        __qlistwidgetitem4->setFont(font6);
        QListWidgetItem *__qlistwidgetitem5 = new QListWidgetItem(listWidget);
        __qlistwidgetitem5->setFont(font5);
        QListWidgetItem *__qlistwidgetitem6 = new QListWidgetItem(listWidget);
        __qlistwidgetitem6->setFont(font5);
        QListWidgetItem *__qlistwidgetitem7 = new QListWidgetItem(listWidget);
        __qlistwidgetitem7->setFont(font5);
        QListWidgetItem *__qlistwidgetitem8 = new QListWidgetItem(listWidget);
        __qlistwidgetitem8->setFont(font5);
        QListWidgetItem *__qlistwidgetitem9 = new QListWidgetItem(listWidget);
        __qlistwidgetitem9->setFont(font5);
        QListWidgetItem *__qlistwidgetitem10 = new QListWidgetItem(listWidget);
        __qlistwidgetitem10->setFont(font5);
        QListWidgetItem *__qlistwidgetitem11 = new QListWidgetItem(listWidget);
        __qlistwidgetitem11->setFont(font5);
        QListWidgetItem *__qlistwidgetitem12 = new QListWidgetItem(listWidget);
        __qlistwidgetitem12->setFont(font5);
        QListWidgetItem *__qlistwidgetitem13 = new QListWidgetItem(listWidget);
        __qlistwidgetitem13->setFont(font5);
        QListWidgetItem *__qlistwidgetitem14 = new QListWidgetItem(listWidget);
        __qlistwidgetitem14->setFont(font5);
        QListWidgetItem *__qlistwidgetitem15 = new QListWidgetItem(listWidget);
        __qlistwidgetitem15->setFont(font5);
        QListWidgetItem *__qlistwidgetitem16 = new QListWidgetItem(listWidget);
        __qlistwidgetitem16->setFont(font5);
        QFont font7;
        font7.setFamily(QString::fromUtf8("Ubuntu"));
        font7.setPointSize(18);
        QListWidgetItem *__qlistwidgetitem17 = new QListWidgetItem(listWidget);
        __qlistwidgetitem17->setFont(font7);
        QListWidgetItem *__qlistwidgetitem18 = new QListWidgetItem(listWidget);
        __qlistwidgetitem18->setFont(font5);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 190, 761, 381));

        retranslateUi(ChatList);

        QMetaObject::connectSlotsByName(ChatList);
    } // setupUi

    void retranslateUi(QWidget *ChatList)
    {
        ChatList->setWindowTitle(QCoreApplication::translate("ChatList", "Form", nullptr));
        label->setText(QCoreApplication::translate("ChatList", "Chat List", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ChatList", "SEARCH", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("ChatList", "hi", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("ChatList", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("ChatList", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("ChatList", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("ChatList", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = listWidget->item(5);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("ChatList", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = listWidget->item(6);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("ChatList", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = listWidget->item(7);
        ___qlistwidgetitem7->setText(QCoreApplication::translate("ChatList", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem8 = listWidget->item(8);
        ___qlistwidgetitem8->setText(QCoreApplication::translate("ChatList", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem9 = listWidget->item(9);
        ___qlistwidgetitem9->setText(QCoreApplication::translate("ChatList", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem10 = listWidget->item(10);
        ___qlistwidgetitem10->setText(QCoreApplication::translate("ChatList", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem11 = listWidget->item(11);
        ___qlistwidgetitem11->setText(QCoreApplication::translate("ChatList", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem12 = listWidget->item(12);
        ___qlistwidgetitem12->setText(QCoreApplication::translate("ChatList", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem13 = listWidget->item(13);
        ___qlistwidgetitem13->setText(QCoreApplication::translate("ChatList", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem14 = listWidget->item(14);
        ___qlistwidgetitem14->setText(QCoreApplication::translate("ChatList", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem15 = listWidget->item(15);
        ___qlistwidgetitem15->setText(QCoreApplication::translate("ChatList", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem16 = listWidget->item(16);
        ___qlistwidgetitem16->setText(QCoreApplication::translate("ChatList", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem17 = listWidget->item(17);
        ___qlistwidgetitem17->setText(QCoreApplication::translate("ChatList", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem18 = listWidget->item(18);
        ___qlistwidgetitem18->setText(QCoreApplication::translate("ChatList", "New Item", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class ChatList: public Ui_ChatList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATLISTTHREAD_H
