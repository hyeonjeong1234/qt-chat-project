/********************************************************************************
** Form generated from reading UI file 'createaccountwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEACCOUNTWIDGET_H
#define UI_CREATEACCOUNTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateAccountWidget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *CreateAccountWidget)
    {
        if (CreateAccountWidget->objectName().isEmpty())
            CreateAccountWidget->setObjectName(QString::fromUtf8("CreateAccountWidget"));
        CreateAccountWidget->resize(800, 600);
        label = new QLabel(CreateAccountWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 20, 411, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(CreateAccountWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(230, 85, 57, 23));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        lineEdit = new QLineEdit(CreateAccountWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(230, 114, 331, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu"));
        font2.setBold(true);
        font2.setWeight(75);
        lineEdit->setFont(font2);
        lineEdit->setCursorMoveStyle(Qt::LogicalMoveStyle);
        lineEdit_2 = new QLineEdit(CreateAccountWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(230, 200, 331, 31));
        lineEdit_2->setFont(font2);
        lineEdit_3 = new QLineEdit(CreateAccountWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(230, 290, 331, 31));
        lineEdit_3->setFont(font2);
        lineEdit_3->setAutoFillBackground(false);
        lineEdit_4 = new QLineEdit(CreateAccountWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(230, 380, 331, 31));
        lineEdit_4->setFont(font2);
        lineEdit_5 = new QLineEdit(CreateAccountWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(230, 470, 331, 31));
        lineEdit_5->setFont(font2);
        label_3 = new QLabel(CreateAccountWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 170, 21, 23));
        label_3->setFont(font1);
        label_4 = new QLabel(CreateAccountWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(230, 260, 31, 23));
        label_4->setFont(font1);
        label_5 = new QLabel(CreateAccountWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(230, 350, 156, 23));
        label_5->setFont(font1);
        label_6 = new QLabel(CreateAccountWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(230, 440, 92, 23));
        label_6->setFont(font1);
        pushButton = new QPushButton(CreateAccountWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(459, 530, 101, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Ubuntu"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        pushButton->setFont(font3);
        pushButton_2 = new QPushButton(CreateAccountWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 530, 101, 31));
        pushButton_2->setFont(font3);

        retranslateUi(CreateAccountWidget);

        QMetaObject::connectSlotsByName(CreateAccountWidget);
    } // setupUi

    void retranslateUi(QWidget *CreateAccountWidget)
    {
        CreateAccountWidget->setWindowTitle(QCoreApplication::translate("CreateAccountWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("CreateAccountWidget", "Create New Account", nullptr));
        label_2->setText(QCoreApplication::translate("CreateAccountWidget", "Name", nullptr));
        label_3->setText(QCoreApplication::translate("CreateAccountWidget", "ID", nullptr));
        label_4->setText(QCoreApplication::translate("CreateAccountWidget", "PW", nullptr));
        label_5->setText(QCoreApplication::translate("CreateAccountWidget", "PHONE NUMBER", nullptr));
        label_6->setText(QCoreApplication::translate("CreateAccountWidget", "ADDRESS", nullptr));
        pushButton->setText(QCoreApplication::translate("CreateAccountWidget", "Create", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CreateAccountWidget", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateAccountWidget: public Ui_CreateAccountWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEACCOUNTWIDGET_H
