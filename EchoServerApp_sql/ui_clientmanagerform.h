/********************************************************************************
** Form generated from reading UI file 'clientmanagerform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTMANAGERFORM_H
#define UI_CLIENTMANAGERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientManagerForm
{
public:
    QSplitter *splitter;
    QListWidget *listWidget;
    QToolBox *toolBox;
    QWidget *inputPage;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout_4;
    QLabel *labelNum;
    QLabel *labelName;
    QLabel *labelAddress;
    QLabel *labelPhoneNumber;
    QLineEdit *lineEditNum;
    QLineEdit *lineEditName;
    QLineEdit *lineEditPhoneNumber;
    QLineEdit *lineEditAddress;
    QLabel *labelPW;
    QLineEdit *lineEditPW;
    QLabel *labelID;
    QLineEdit *lineEditID;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButtonModify;
    QWidget *SearchPage;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidgetSearch;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *lineEditSearch;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_3;

    void setupUi(QWidget *ClientManagerForm)
    {
        if (ClientManagerForm->objectName().isEmpty())
            ClientManagerForm->setObjectName(QString::fromUtf8("ClientManagerForm"));
        ClientManagerForm->resize(800, 600);
        splitter = new QSplitter(ClientManagerForm);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(10, 10, 412, 307));
        splitter->setOrientation(Qt::Horizontal);
        listWidget = new QListWidget(splitter);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        splitter->addWidget(listWidget);
        toolBox = new QToolBox(splitter);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        inputPage = new QWidget();
        inputPage->setObjectName(QString::fromUtf8("inputPage"));
        inputPage->setGeometry(QRect(0, 0, 202, 249));
        verticalLayout = new QVBoxLayout(inputPage);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        labelNum = new QLabel(inputPage);
        labelNum->setObjectName(QString::fromUtf8("labelNum"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, labelNum);

        labelName = new QLabel(inputPage);
        labelName->setObjectName(QString::fromUtf8("labelName"));

        formLayout_4->setWidget(3, QFormLayout::LabelRole, labelName);

        labelAddress = new QLabel(inputPage);
        labelAddress->setObjectName(QString::fromUtf8("labelAddress"));

        formLayout_4->setWidget(5, QFormLayout::LabelRole, labelAddress);

        labelPhoneNumber = new QLabel(inputPage);
        labelPhoneNumber->setObjectName(QString::fromUtf8("labelPhoneNumber"));

        formLayout_4->setWidget(4, QFormLayout::LabelRole, labelPhoneNumber);

        lineEditNum = new QLineEdit(inputPage);
        lineEditNum->setObjectName(QString::fromUtf8("lineEditNum"));
        lineEditNum->setReadOnly(true);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, lineEditNum);

        lineEditName = new QLineEdit(inputPage);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));

        formLayout_4->setWidget(3, QFormLayout::FieldRole, lineEditName);

        lineEditPhoneNumber = new QLineEdit(inputPage);
        lineEditPhoneNumber->setObjectName(QString::fromUtf8("lineEditPhoneNumber"));

        formLayout_4->setWidget(4, QFormLayout::FieldRole, lineEditPhoneNumber);

        lineEditAddress = new QLineEdit(inputPage);
        lineEditAddress->setObjectName(QString::fromUtf8("lineEditAddress"));

        formLayout_4->setWidget(5, QFormLayout::FieldRole, lineEditAddress);

        labelPW = new QLabel(inputPage);
        labelPW->setObjectName(QString::fromUtf8("labelPW"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, labelPW);

        lineEditPW = new QLineEdit(inputPage);
        lineEditPW->setObjectName(QString::fromUtf8("lineEditPW"));

        formLayout_4->setWidget(2, QFormLayout::FieldRole, lineEditPW);

        labelID = new QLabel(inputPage);
        labelID->setObjectName(QString::fromUtf8("labelID"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, labelID);

        lineEditID = new QLineEdit(inputPage);
        lineEditID->setObjectName(QString::fromUtf8("lineEditID"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, lineEditID);


        verticalLayout->addLayout(formLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(inputPage);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButtonModify = new QPushButton(inputPage);
        pushButtonModify->setObjectName(QString::fromUtf8("pushButtonModify"));

        horizontalLayout->addWidget(pushButtonModify);


        verticalLayout->addLayout(horizontalLayout);

        toolBox->addItem(inputPage, QString::fromUtf8("Input"));
        SearchPage = new QWidget();
        SearchPage->setObjectName(QString::fromUtf8("SearchPage"));
        SearchPage->setGeometry(QRect(0, 0, 202, 249));
        verticalLayout_2 = new QVBoxLayout(SearchPage);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        listWidgetSearch = new QListWidget(SearchPage);
        listWidgetSearch->setObjectName(QString::fromUtf8("listWidgetSearch"));

        verticalLayout_2->addWidget(listWidgetSearch);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(SearchPage);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        lineEditSearch = new QLineEdit(SearchPage);
        lineEditSearch->setObjectName(QString::fromUtf8("lineEditSearch"));

        horizontalLayout_2->addWidget(lineEditSearch);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_3 = new QPushButton(SearchPage);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_3->addWidget(pushButton_3);


        verticalLayout_2->addLayout(horizontalLayout_3);

        toolBox->addItem(SearchPage, QString::fromUtf8("Search"));
        splitter->addWidget(toolBox);
#if QT_CONFIG(shortcut)
        labelNum->setBuddy(lineEditNum);
        labelName->setBuddy(lineEditName);
        labelAddress->setBuddy(lineEditAddress);
        labelPhoneNumber->setBuddy(lineEditPhoneNumber);
        label_5->setBuddy(lineEditSearch);
#endif // QT_CONFIG(shortcut)

        retranslateUi(ClientManagerForm);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ClientManagerForm);
    } // setupUi

    void retranslateUi(QWidget *ClientManagerForm)
    {
        ClientManagerForm->setWindowTitle(QCoreApplication::translate("ClientManagerForm", "Form", nullptr));
        labelNum->setText(QCoreApplication::translate("ClientManagerForm", "Num", nullptr));
        labelName->setText(QCoreApplication::translate("ClientManagerForm", "&Name", nullptr));
        labelAddress->setText(QCoreApplication::translate("ClientManagerForm", "&Address", nullptr));
        labelPhoneNumber->setText(QCoreApplication::translate("ClientManagerForm", "&Phone Number", nullptr));
        labelPW->setText(QCoreApplication::translate("ClientManagerForm", "Password", nullptr));
        labelID->setText(QCoreApplication::translate("ClientManagerForm", "ID", nullptr));
        pushButton->setText(QCoreApplication::translate("ClientManagerForm", "&Add", nullptr));
        pushButtonModify->setText(QCoreApplication::translate("ClientManagerForm", "&Modify", nullptr));
        toolBox->setItemText(toolBox->indexOf(inputPage), QCoreApplication::translate("ClientManagerForm", "Input", nullptr));
        label_5->setText(QCoreApplication::translate("ClientManagerForm", "&ID", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ClientManagerForm", "Search", nullptr));
        toolBox->setItemText(toolBox->indexOf(SearchPage), QCoreApplication::translate("ClientManagerForm", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientManagerForm: public Ui_ClientManagerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTMANAGERFORM_H
