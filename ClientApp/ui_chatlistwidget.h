/********************************************************************************
** Form generated from reading UI file 'chatlistwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATLISTWIDGET_H
#define UI_CHATLISTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatListWidget
{
public:
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_3;
    QListWidget *listWidget;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *ChatListWidget)
    {
        if (ChatListWidget->objectName().isEmpty())
            ChatListWidget->setObjectName(QString::fromUtf8("ChatListWidget"));
        ChatListWidget->resize(800, 600);
        lineEdit_3 = new QLineEdit(ChatListWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(20, 100, 471, 51));
        pushButton_3 = new QPushButton(ChatListWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(510, 100, 101, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        pushButton_3->setFont(font);
        listWidget = new QListWidget(ChatListWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 180, 761, 391));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        listWidget->setFont(font1);
        label = new QLabel(ChatListWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(320, 20, 151, 71));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu"));
        font2.setPointSize(24);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        pushButton = new QPushButton(ChatListWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(630, 100, 151, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Ubuntu"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        pushButton->setFont(font3);

        retranslateUi(ChatListWidget);

        QMetaObject::connectSlotsByName(ChatListWidget);
    } // setupUi

    void retranslateUi(QWidget *ChatListWidget)
    {
        ChatListWidget->setWindowTitle(QCoreApplication::translate("ChatListWidget", "Form", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ChatListWidget", "SEARCH", nullptr));
        label->setText(QCoreApplication::translate("ChatListWidget", "Chat List", nullptr));
        pushButton->setText(QCoreApplication::translate("ChatListWidget", "NEW CHAT ROOM", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatListWidget: public Ui_ChatListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATLISTWIDGET_H
