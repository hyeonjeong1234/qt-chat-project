/********************************************************************************
** Form generated from reading UI file 'chatlist.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATLIST_H
#define UI_CHATLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatList
{
public:
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *tab_2;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;

    void setupUi(QWidget *ChatList)
    {
        if (ChatList->objectName().isEmpty())
            ChatList->setObjectName(QString::fromUtf8("ChatList"));
        ChatList->resize(800, 600);
        label = new QLabel(ChatList);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(310, 10, 151, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        tabWidget = new QTabWidget(ChatList);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 80, 761, 501));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        scrollArea = new QScrollArea(tab);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 761, 471));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 759, 469));
        scrollArea->setWidget(scrollAreaWidgetContents);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        scrollArea_2 = new QScrollArea(tab_2);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(0, 0, 771, 501));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 769, 499));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        tabWidget->addTab(tab_2, QString());

        retranslateUi(ChatList);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ChatList);
    } // setupUi

    void retranslateUi(QWidget *ChatList)
    {
        ChatList->setWindowTitle(QCoreApplication::translate("ChatList", "Form", nullptr));
        label->setText(QCoreApplication::translate("ChatList", "Chat List", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("ChatList", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("ChatList", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatList: public Ui_ChatList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATLIST_H
