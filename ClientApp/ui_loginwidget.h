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
    QPushButton *pushButton_3;

    void setupUi(QWidget *LoginWidget)
    {
        if (LoginWidget->objectName().isEmpty())
            LoginWidget->setObjectName(QString::fromUtf8("LoginWidget"));
        LoginWidget->resize(800, 600);
        label_2 = new QLabel(LoginWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(270, 210, 20, 22));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        pushButton = new QPushButton(LoginWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(360, 330, 80, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton->setFont(font1);
        label_3 = new QLabel(LoginWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(260, 277, 41, 21));
        label_3->setFont(font);
        IDEdit = new QLineEdit(LoginWidget);
        IDEdit->setObjectName(QString::fromUtf8("IDEdit"));
        IDEdit->setGeometry(QRect(300, 210, 211, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu"));
        font2.setBold(true);
        font2.setWeight(75);
        IDEdit->setFont(font2);
        PWEdit = new QLineEdit(LoginWidget);
        PWEdit->setObjectName(QString::fromUtf8("PWEdit"));
        PWEdit->setGeometry(QRect(300, 270, 211, 31));
        PWEdit->setFont(font2);
        PWEdit->setEchoMode(QLineEdit::Password);
        label = new QLabel(LoginWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(275, 130, 231, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Ubuntu"));
        font3.setPointSize(34);
        font3.setBold(true);
        font3.setWeight(75);
        label->setFont(font3);
        label->setAlignment(Qt::AlignCenter);
        pushButton_2 = new QPushButton(LoginWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(320, 390, 164, 31));
        pushButton_2->setFont(font1);
        pushButton_3 = new QPushButton(LoginWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(360, 450, 81, 31));
        pushButton_3->setFont(font1);

        retranslateUi(LoginWidget);
        QObject::connect(pushButton_3, SIGNAL(clicked()), LoginWidget, SLOT(close()));

        QMetaObject::connectSlotsByName(LoginWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginWidget)
    {
        LoginWidget->setWindowTitle(QCoreApplication::translate("LoginWidget", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWidget", "ID", nullptr));
        pushButton->setText(QCoreApplication::translate("LoginWidget", "Sign In", nullptr));
        label_3->setText(QCoreApplication::translate("LoginWidget", "PW", nullptr));
        IDEdit->setText(QString());
        label->setText(QCoreApplication::translate("LoginWidget", "WELCOME", nullptr));
        pushButton_2->setText(QCoreApplication::translate("LoginWidget", "Create New Account", nullptr));
        pushButton_3->setText(QCoreApplication::translate("LoginWidget", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWidget: public Ui_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
