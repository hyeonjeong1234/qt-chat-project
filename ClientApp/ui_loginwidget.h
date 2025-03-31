/********************************************************************************
** Form generated from reading UI file 'loginwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWidget
{
public:
    QLabel *label_2;
    QPushButton *pushButton;
    QLabel *label_3;
    QLineEdit *IDEdit;
    QLineEdit *PWEdit;
    QLabel *label;
    QPushButton *pushButton_2;

    void setupUi(QWidget *LoginWidget)
    {
        if (LoginWidget->objectName().isEmpty())
            LoginWidget->setObjectName(QString::fromUtf8("LoginWidget"));
        LoginWidget->resize(800, 600);
        LoginWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(116, 88, 80);"));
        label_2 = new QLabel(LoginWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(234, 242, 41, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("BM JUA_TTF"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(214, 192, 175);\n"
"background-color:transparent;\n"
"font: 20pt \"BM JUA_TTF\";"));
        pushButton = new QPushButton(LoginWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(250, 400, 91, 41));
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
        label_3 = new QLabel(LoginWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(234, 310, 51, 41));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(214, 192, 175);\n"
"background-color:transparent;\n"
"font: 20pt \"BM JUA_TTF\";"));
        IDEdit = new QLineEdit(LoginWidget);
        IDEdit->setObjectName(QString::fromUtf8("IDEdit"));
        IDEdit->setGeometry(QRect(284, 240, 311, 41));
        IDEdit->setFont(font);
        IDEdit->setStyleSheet(QString::fromUtf8("color: rgb(116, 88, 80);\n"
"border-style: solid;\n"
"border-width: 3px;\n"
"border-color:rgb(214, 192, 175);\n"
"border-radius: 7;\n"
"background-color: rgb(197, 165, 142);\n"
"font: 20pt \"BM JUA_TTF\";\n"
"padding-left: 10px; padding-right: 10px;"));
        PWEdit = new QLineEdit(LoginWidget);
        PWEdit->setObjectName(QString::fromUtf8("PWEdit"));
        PWEdit->setGeometry(QRect(284, 310, 311, 41));
        PWEdit->setFont(font);
        PWEdit->setStyleSheet(QString::fromUtf8("color: rgb(116, 88, 80);\n"
"border-style: solid;\n"
"border-width: 3px;\n"
"border-color:rgb(214, 192, 175);\n"
"border-radius: 7px;\n"
"background-color: rgb(197, 165, 142);\n"
"font: 20pt \"BM JUA_TTF\";\n"
"padding-left: 10px; padding-right: 10px;"));
        PWEdit->setEchoMode(QLineEdit::Password);
        label = new QLabel(LoginWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 150, 541, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu"));
        font2.setPointSize(34);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("color: rgb(214, 192, 175);\n"
"background-color:transparent;"));
        label->setAlignment(Qt::AlignCenter);
        pushButton_2 = new QPushButton(LoginWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(370, 400, 211, 41));
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
        QWidget::setTabOrder(IDEdit, PWEdit);
        QWidget::setTabOrder(PWEdit, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_2);

        retranslateUi(LoginWidget);

        QMetaObject::connectSlotsByName(LoginWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginWidget)
    {
        LoginWidget->setWindowTitle(QCoreApplication::translate("LoginWidget", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWidget", "ID", nullptr));
        pushButton->setText(QCoreApplication::translate("LoginWidget", "Sign In", nullptr));
        label_3->setText(QCoreApplication::translate("LoginWidget", "PW", nullptr));
        IDEdit->setText(QString());
        label->setText(QCoreApplication::translate("LoginWidget", "HAPPY CHAT PROGRAM", nullptr));
        pushButton_2->setText(QCoreApplication::translate("LoginWidget", "Create New Account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWidget: public Ui_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
