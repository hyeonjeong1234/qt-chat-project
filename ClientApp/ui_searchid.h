/********************************************************************************
** Form generated from reading UI file 'searchid.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHID_H
#define UI_SEARCHID_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchId
{
public:
    QLabel *label;
    QSplitter *splitter;
    QListWidget *listWidget;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_3;

    void setupUi(QWidget *SearchId)
    {
        if (SearchId->objectName().isEmpty())
            SearchId->setObjectName(QString::fromUtf8("SearchId"));
        SearchId->resize(800, 600);
        label = new QLabel(SearchId);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(250, 30, 311, 42));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(28);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        splitter = new QSplitter(SearchId);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(10, 170, 771, 411));
        splitter->setOrientation(Qt::Horizontal);
        listWidget = new QListWidget(splitter);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        listWidget->setFont(font1);
        splitter->addWidget(listWidget);
        lineEdit_3 = new QLineEdit(SearchId);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(10, 100, 651, 51));
        pushButton_3 = new QPushButton(SearchId);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(680, 100, 101, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_3->setFont(font2);

        retranslateUi(SearchId);

        QMetaObject::connectSlotsByName(SearchId);
    } // setupUi

    void retranslateUi(QWidget *SearchId)
    {
        SearchId->setWindowTitle(QCoreApplication::translate("SearchId", "Form", nullptr));
        label->setText(QCoreApplication::translate("SearchId", "Make Group Chat", nullptr));
        pushButton_3->setText(QCoreApplication::translate("SearchId", "SEARCH", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchId: public Ui_SearchId {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHID_H
