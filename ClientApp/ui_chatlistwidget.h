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
        ChatListWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(116, 88, 80);"));
        lineEdit_3 = new QLineEdit(ChatListWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(20, 100, 471, 51));
        lineEdit_3->setStyleSheet(QString::fromUtf8("color: rgb(116, 88, 80);\n"
"border-style: solid;\n"
"border-width: 3px;\n"
"border-color:rgb(214, 192, 175);\n"
"border-radius: 10;\n"
"background-color: rgb(197, 165, 142);\n"
"font: 20pt \"BM JUA_TTF\";\n"
"padding-left: 10px; padding-right: 10px;"));
        lineEdit_3->setDragEnabled(true);
        pushButton_3 = new QPushButton(ChatListWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(510, 100, 101, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("BM JUA_TTF"));
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 16pt \"BM JUA_TTF\";\n"
"	background-color: rgb(197, 165, 142);\n"
"	border: none;\n"
"	border-radius: 10px;\n"
"	\n"
"	color: rgb(116, 88, 80);\n"
"	\n"
"    border-left: 3px solid rgb(214, 192, 175);\n"
"	border-right: 3px solid rgb(214, 192, 175);\n"
"	border-bottom: 3px solid rgb(214, 192, 175);\n"
"	border-top: 3px solid rgb(214, 192, 175);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(197, 165, 142);\n"
"	\n"
"	color: rgb(214, 192, 175);\n"
"	\n"
"    border-left: 3px solid rgb(214, 192, 175);\n"
"	border-right: 3px solid rgb(214, 192, 175);\n"
"	border-bottom: 3px solid rgb(214, 192, 175);\n"
"	border-top: 3px solid rgb(214, 192, 175);\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(214, 192, 175);\n"
"	background-color:  rgb(116, 88, 80);\n"
"	border-top: 3px solid rgb(214, 192, 175);\n"
"	border-left: 3px solid rgb(214, 192, 175);\n"
"	border-right: 3px solid rgb(214, 192, 175);\n"
"	border-bottom: 3px solid rgb(214, 192, 175);\n"
"\n"
"}"));
        listWidget = new QListWidget(ChatListWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 180, 761, 391));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        listWidget->setFont(font1);
        listWidget->setStyleSheet(QString::fromUtf8("color: rgb(116, 88, 80);\n"
"border-style: solid;\n"
"border-width: 3px;\n"
"border-color:rgb(214, 192, 175);\n"
"border-radius: 10;\n"
"background-color: rgb(197, 165, 142);"));
        label = new QLabel(ChatListWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(320, 20, 141, 71));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu"));
        font2.setPointSize(24);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("color: rgb(214, 192, 175);\n"
"background-color:transparent;"));
        pushButton = new QPushButton(ChatListWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(630, 100, 151, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("BM JUA_TTF"));
        font3.setPointSize(13);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        pushButton->setFont(font3);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 13pt \"BM JUA_TTF\";\n"
"	background-color: rgb(197, 165, 142);\n"
"	border: none;\n"
"	border-radius: 10px;\n"
"	\n"
"	color: rgb(116, 88, 80);\n"
"	\n"
"    border-left: 3px solid rgb(214, 192, 175);\n"
"	border-right: 3px solid rgb(214, 192, 175);\n"
"	border-bottom: 3px solid rgb(214, 192, 175);\n"
"	border-top: 3px solid rgb(214, 192, 175);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(197, 165, 142);\n"
"	\n"
"	color: rgb(214, 192, 175);\n"
"	\n"
"    border-left: 3px solid rgb(214, 192, 175);\n"
"	border-right: 3px solid rgb(214, 192, 175);\n"
"	border-bottom: 3px solid rgb(214, 192, 175);\n"
"	border-top: 3px solid rgb(214, 192, 175);\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(214, 192, 175);\n"
"	background-color:  rgb(116, 88, 80);\n"
"	border-top: 3px solid rgb(214, 192, 175);\n"
"	border-left: 3px solid rgb(214, 192, 175);\n"
"	border-right: 3px solid rgb(214, 192, 175);\n"
"	border-bottom: 3px solid rgb(214, 192, 175);\n"
"\n"
"}"));

        retranslateUi(ChatListWidget);

        QMetaObject::connectSlotsByName(ChatListWidget);
    } // setupUi

    void retranslateUi(QWidget *ChatListWidget)
    {
        ChatListWidget->setWindowTitle(QCoreApplication::translate("ChatListWidget", "Form", nullptr));
        lineEdit_3->setText(QString());
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
