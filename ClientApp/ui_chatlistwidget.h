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
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QListWidget *listWidget;

    void setupUi(QWidget *ChatListWidget)
    {
        if (ChatListWidget->objectName().isEmpty())
            ChatListWidget->setObjectName(QString::fromUtf8("ChatListWidget"));
        ChatListWidget->resize(800, 641);
        ChatListWidget->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        lineEdit_3 = new QLineEdit(ChatListWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(20, 136, 471, 51));
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
        pushButton_3->setGeometry(QRect(510, 136, 101, 51));
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
        label = new QLabel(ChatListWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(320, 56, 141, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(24);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: rgb(214, 192, 175);\n"
"background-color:transparent;"));
        pushButton = new QPushButton(ChatListWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(630, 136, 151, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("BM JUA_TTF"));
        font2.setPointSize(13);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        pushButton->setFont(font2);
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
        pushButton_5 = new QPushButton(ChatListWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(659, 4, 32, 32));
        pushButton_5->setFont(font);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 16pt \"BM JUA_TTF\";\n"
"	background-color: rgb(197, 165, 142);\n"
"	border: none;\n"
"	border-radius:10px;\n"
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
        pushButton_4 = new QPushButton(ChatListWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(707, 4, 32, 32));
        pushButton_4->setFont(font);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 16pt \"BM JUA_TTF\";\n"
"	background-color: rgb(197, 165, 142);\n"
"	border: none;\n"
"	border-radius:10px;\n"
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
        label_2 = new QLabel(ChatListWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 800, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("BM JUA_TTF"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        label_2->setFont(font3);
        label_2->setStyleSheet(QString::fromUtf8("color:rgba(170,170,170,255);\n"
"background-color: rgb(197, 165, 142);\n"
"border-top-left-radius: 10px;\n"
"border-top-right-radius: 10px;"));
        pushButton_2 = new QPushButton(ChatListWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(755, 4, 32, 32));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        listWidget->setGeometry(QRect(20, 213, 761, 391));
        QFont font4;
        font4.setFamily(QString::fromUtf8("BM JUA_TTF"));
        font4.setPointSize(24);
        listWidget->setFont(font4);
        listWidget->setStyleSheet(QString::fromUtf8("QListView {\n"
"    color: rgb(116, 88, 80);\n"
"	border-style: solid;\n"
"	border-width: 3px;\n"
"	border-color:rgb(214, 192, 175);\n"
"	border-radius: 10;\n"
"	background-color: rgb(197, 165, 142);\n"
" 	show-decoration-selected: 1; \n"
"	\n"
"}\n"
"\n"
"QListView::item:alternate {\n"
"   \n"
"	    color:rgb(214, 192, 175);\n"
"	background-color:rgb(255, 0, 0);\n"
"border-width: 3px;\n"
"	border-color:rgb(172, 137, 116);\n"
"	border-radius: 5;\n"
"}\n"
"\n"
"QListView::item:selected {\n"
"    color:rgb(214, 192, 175);\n"
"	background-color:rgb(255, 162, 0);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QListView::item:selected:!active {\n"
"	  color:rgb(214, 192, 175);\n"
"	background-color:rgb(116, 88, 80);\n"
"border-width: 3px;\n"
"	border-color:rgb(214, 192, 175);\n"
"	border-radius: 5;\n"
"}\n"
"\n"
"QListView::item:selected:active {\n"
"    color:rgb(116, 88, 80);\n"
"	background-color:rgb(214, 192, 175);\n"
"border-width: 3px;\n"
"	border-color:rgb(172, 137, 116);\n"
"	border-radius: 5;\n"
"\n"
"}\n"
"\n"
""
                        "QListView::item:hover {\n"
"    color: rgb(214, 192, 175);\n"
"	background-color: transparent;\n"
"	border-width: 3px;\n"
"	border-color:rgb(172, 137, 116);\n"
"	border-radius: 5;\n"
"}"));
        label_2->raise();
        lineEdit_3->raise();
        pushButton_3->raise();
        label->raise();
        pushButton->raise();
        pushButton_5->raise();
        pushButton_4->raise();
        pushButton_2->raise();
        listWidget->raise();

        retranslateUi(ChatListWidget);
        QObject::connect(pushButton_2, SIGNAL(clicked()), ChatListWidget, SLOT(close()));

        QMetaObject::connectSlotsByName(ChatListWidget);
    } // setupUi

    void retranslateUi(QWidget *ChatListWidget)
    {
        ChatListWidget->setWindowTitle(QCoreApplication::translate("ChatListWidget", "Form", nullptr));
        lineEdit_3->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("ChatListWidget", "SEARCH", nullptr));
        label->setText(QCoreApplication::translate("ChatListWidget", "Chat List", nullptr));
        pushButton->setText(QCoreApplication::translate("ChatListWidget", "NEW CHAT ROOM", nullptr));
        pushButton_5->setText(QString());
        pushButton_4->setText(QString());
        label_2->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChatListWidget: public Ui_ChatListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATLISTWIDGET_H
