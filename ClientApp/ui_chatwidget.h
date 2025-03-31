/********************************************************************************
** Form generated from reading UI file 'chatwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWIDGET_H
#define UI_CHATWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWidget
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QWidget *ChatWidget)
    {
        if (ChatWidget->objectName().isEmpty())
            ChatWidget->setObjectName(QString::fromUtf8("ChatWidget"));
        ChatWidget->resize(715, 703);
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        ChatWidget->setFont(font);
        ChatWidget->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(ChatWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(594, 622, 81, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("BM JUA_TTF"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        lineEdit = new QLineEdit(ChatWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(37, 611, 521, 61));
        QFont font2;
        font2.setFamily(QString::fromUtf8("BM JUA_TTF"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        lineEdit->setFont(font2);
        lineEdit->setStyleSheet(QString::fromUtf8("color: rgb(116, 88, 80);\n"
"border-style: solid;\n"
"border-width: 3px;\n"
"border-color: rgb(214, 192, 175);\n"
"border-radius: 10;\n"
"background-color: rgb(197, 165, 142);\n"
"\n"
"padding-left: 10px; padding-right: 10px;"));
        textEdit = new QTextEdit(ChatWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(36, 71, 641, 521));
        QFont font3;
        font3.setFamily(QString::fromUtf8("BM JUA_TTF"));
        font3.setPointSize(16);
        font3.setBold(false);
        font3.setWeight(50);
        textEdit->setFont(font3);
        textEdit->setStyleSheet(QString::fromUtf8("color: rgb(116, 88, 80);\n"
"border-style: solid;\n"
"border-width: 3px;\n"
"border-color:rgb(214, 192, 175);\n"
"border-radius: 10;\n"
"background-color: rgb(197, 165, 142);"));
        textEdit->setReadOnly(true);
        pushButton_2 = new QPushButton(ChatWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(664, 2, 36, 36));
        pushButton_2->setFont(font1);
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
        label = new QLabel(ChatWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 715, 41));
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("color:rgba(170,170,170,255);\n"
"background-color: rgb(197, 165, 142);\n"
"border-top-left-radius: 10px;\n"
"border-top-right-radius: 10px;"));
        label_2 = new QLabel(ChatWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 715, 41));
        QFont font4;
        font4.setFamily(QString::fromUtf8("BM JUA_TTF"));
        font4.setPointSize(24);
        font4.setBold(false);
        font4.setWeight(50);
        label_2->setFont(font4);
        label_2->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: rgb(116, 88, 80);\n"
"border-top-left-radius: 10px;\n"
"border-top-right-radius: 10px;\n"
"padding-left: 147px; padding-right: 187px;"));
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setMargin(0);
        pushButton_4 = new QPushButton(ChatWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(616, 2, 36, 36));
        pushButton_4->setFont(font1);
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
        pushButton_5 = new QPushButton(ChatWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(568, 2, 36, 36));
        pushButton_5->setFont(font1);
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
        label_2->raise();
        label->raise();
        pushButton->raise();
        lineEdit->raise();
        textEdit->raise();
        pushButton_2->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        QWidget::setTabOrder(lineEdit, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_2);
        QWidget::setTabOrder(pushButton_2, textEdit);

        retranslateUi(ChatWidget);
        QObject::connect(pushButton_2, SIGNAL(clicked()), textEdit, SLOT(clear()));

        QMetaObject::connectSlotsByName(ChatWidget);
    } // setupUi

    void retranslateUi(QWidget *ChatWidget)
    {
        ChatWidget->setWindowTitle(QCoreApplication::translate("ChatWidget", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("ChatWidget", "SEND", nullptr));
        lineEdit->setPlaceholderText(QString());
        pushButton_2->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChatWidget: public Ui_ChatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWIDGET_H
