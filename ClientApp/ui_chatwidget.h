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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWidget
{
public:
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QTextEdit *textEdit_2;

    void setupUi(QWidget *ChatWidget)
    {
        if (ChatWidget->objectName().isEmpty())
            ChatWidget->setObjectName(QString::fromUtf8("ChatWidget"));
        ChatWidget->resize(800, 703);
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        ChatWidget->setFont(font);
        ChatWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(116, 88, 80);"));
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
        textEdit = new QTextEdit(ChatWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(36, 131, 641, 461));
        QFont font2;
        font2.setFamily(QString::fromUtf8("BM JUA_TTF"));
        font2.setPointSize(16);
        font2.setBold(false);
        font2.setWeight(50);
        textEdit->setFont(font2);
        textEdit->setStyleSheet(QString::fromUtf8("color: rgb(116, 88, 80);\n"
"border-style: solid;\n"
"border-width: 3px;\n"
"border-color:rgb(214, 192, 175);\n"
"border-radius: 10;\n"
"background-color: rgb(197, 165, 142);"));
        textEdit->setReadOnly(true);
        pushButton_2 = new QPushButton(ChatWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(715, 4, 32, 32));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 16pt \"BM JUA_TTF\";\n"
"	\n"
"	background-color:  transparent;\n"
"	background-repeat: no-repeat;\n"
"    background-position: center;\n"
"	\n"
"	background-image:url(:/window_icons/size_mid.png);\n"
"\n"
"	border: none;\n"
"	border-radius:10px;\n"
"	\n"
"	color: rgb(116, 88, 80);\n"
"	\n"
"    border-left: 0px solid rgb(214, 192, 175);\n"
"	border-right: 0px solid rgb(214, 192, 175);\n"
"	border-bottom: 0px solid rgb(214, 192, 175);\n"
"	border-top: 0px solid rgb(214, 192, 175);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color:  transparent;\n"
"	\n"
"	background-image:url(:/window_icons/size.png);\n"
"	color: rgb(214, 192, 175);\n"
"	\n"
"    border-left: 0px solid rgb(214, 192, 175);\n"
"	border-right: 0px solid rgb(214, 192, 175);\n"
"	border-bottom: 0px solid rgb(214, 192, 175);\n"
"	border-top: 0px solid rgb(214, 192, 175);\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(214, 192, 175);\n"
"	\n"
"	background-image: url(:/window_icons/size_darl.png);\n"
"	background-col"
                        "or:  transparent;\n"
"	border-top: 0px solid rgb(214, 192, 175);\n"
"	border-left: 0px solid rgb(214, 192, 175);\n"
"	border-right: 0px solid rgb(214, 192, 175);\n"
"	border-bottom:0px solid rgb(214, 192, 175);\n"
"\n"
"}"));
        label = new QLabel(ChatWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 800, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("BM JUA_TTF"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8("color:rgba(170,170,170,255);\n"
"background-color: rgb(197, 165, 142);\n"
"border-top-left-radius: 10px;\n"
"border-top-right-radius: 10px;"));
        label_2 = new QLabel(ChatWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 40, 800, 71));
        QFont font4;
        font4.setFamily(QString::fromUtf8("BM JUA_TTF"));
        font4.setPointSize(24);
        font4.setBold(false);
        font4.setWeight(50);
        label_2->setFont(font4);
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 199, 181);\n"
"color:rgb(116, 88, 80);\n"
"padding-left: 50px; padding-right: 50px;"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_2->setMargin(0);
        pushButton_4 = new QPushButton(ChatWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(675, 4, 32, 32));
        pushButton_4->setFont(font1);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 16pt \"BM JUA_TTF\";\n"
"	\n"
"	background-color:  transparent;\n"
"	background-repeat: no-repeat;\n"
"    background-position: center;\n"
"	\n"
"	background-image: url(:/window_icons/_mid.png);\n"
"	border: none;\n"
"	border-radius:10px;\n"
"	\n"
"	color: rgb(116, 88, 80);\n"
"	\n"
"    border-left: 0px solid rgb(214, 192, 175);\n"
"	border-right: 0px solid rgb(214, 192, 175);\n"
"	border-bottom: 0px solid rgb(214, 192, 175);\n"
"	border-top: 0px solid rgb(214, 192, 175);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color:  transparent;\n"
"	\n"
"	background-image: url(:/window_icons/_.png);\n"
"	color: rgb(214, 192, 175);\n"
"	\n"
"    border-left: 0px solid rgb(214, 192, 175);\n"
"	border-right: 0px solid rgb(214, 192, 175);\n"
"	border-bottom: 0px solid rgb(214, 192, 175);\n"
"	border-top: 0px solid rgb(214, 192, 175);\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(214, 192, 175);\n"
"	\n"
"	background-image: url(:/window_icons/_dark.png);\n"
"	background-color:  transpare"
                        "nt;\n"
"	border-top: 0px solid rgb(214, 192, 175);\n"
"	border-left: 0px solid rgb(214, 192, 175);\n"
"	border-right: 0px solid rgb(214, 192, 175);\n"
"	border-bottom:0px solid rgb(214, 192, 175);\n"
"\n"
"}"));
        pushButton_5 = new QPushButton(ChatWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(755, 4, 32, 32));
        pushButton_5->setFont(font1);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 16pt \"BM JUA_TTF\";\n"
"	\n"
"	background-color:  transparent;\n"
"	background-repeat: no-repeat;\n"
"    background-position: center;\n"
"	\n"
"	background-image:url(:/window_icons/close_mid.png);\n"
"\n"
"	border: none;\n"
"	border-radius:10px;\n"
"	\n"
"	color: rgb(116, 88, 80);\n"
"	\n"
"    border-left: 0px solid rgb(214, 192, 175);\n"
"	border-right: 0px solid rgb(214, 192, 175);\n"
"	border-bottom: 0px solid rgb(214, 192, 175);\n"
"	border-top: 0px solid rgb(214, 192, 175);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color:  transparent;\n"
"	\n"
"	background-image:url(:/window_icons/close.png);\n"
"	color: rgb(214, 192, 175);\n"
"	\n"
"    border-left: 0px solid rgb(214, 192, 175);\n"
"	border-right: 0px solid rgb(214, 192, 175);\n"
"	border-bottom: 0px solid rgb(214, 192, 175);\n"
"	border-top: 0px solid rgb(214, 192, 175);\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(214, 192, 175);\n"
"	\n"
"	background-image: url(:/window_icons/close_dark.png);\n"
"	background-"
                        "color:  transparent;\n"
"	border-top: 0px solid rgb(214, 192, 175);\n"
"	border-left: 0px solid rgb(214, 192, 175);\n"
"	border-right: 0px solid rgb(214, 192, 175);\n"
"	border-bottom:0px solid rgb(214, 192, 175);\n"
"\n"
"}"));
        textEdit_2 = new QTextEdit(ChatWidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(37, 611, 541, 59));
        QFont font5;
        font5.setFamily(QString::fromUtf8("BM JUA_TTF"));
        font5.setPointSize(18);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(50);
        textEdit_2->setFont(font5);
        textEdit_2->setStyleSheet(QString::fromUtf8("color: rgb(116, 88, 80);\n"
"font: 18pt \"BM JUA_TTF\";\n"
"border-style: solid;\n"
"border-width: 3px;\n"
"border-color:rgb(214, 192, 175);\n"
"border-radius: 10;\n"
"background-color: rgb(197, 165, 142);"));
        textEdit_2->setReadOnly(false);
        label_2->raise();
        label->raise();
        pushButton->raise();
        textEdit->raise();
        pushButton_2->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        textEdit_2->raise();
        QWidget::setTabOrder(pushButton, pushButton_2);
        QWidget::setTabOrder(pushButton_2, textEdit);

        retranslateUi(ChatWidget);
        QObject::connect(pushButton_5, SIGNAL(clicked()), ChatWidget, SLOT(close()));

        QMetaObject::connectSlotsByName(ChatWidget);
    } // setupUi

    void retranslateUi(QWidget *ChatWidget)
    {
        ChatWidget->setWindowTitle(QCoreApplication::translate("ChatWidget", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("ChatWidget", "SEND", nullptr));
        pushButton_2->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        textEdit_2->setHtml(QCoreApplication::translate("ChatWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'BM JUA_TTF'; font-size:18pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatWidget: public Ui_ChatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWIDGET_H
