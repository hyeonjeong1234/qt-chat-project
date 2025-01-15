#include "loginwidget.h"
#include "ui_loginwidget.h"
#include <QStyle>
#include <QDesktopWidget>
#include<QDebug>
LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidget)
{
    ui->setupUi(this);


this->setGeometry(
    QStyle::alignedRect(
        Qt::LeftToRight,
        Qt::AlignCenter,
        this->size(),
        qApp->desktop()->availableGeometry())
    );
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

void LoginWidget::on_pushButton_clicked()
{
    //this->hide();
    QString newLoginInfo;
    newLoginInfo =  ui->IDEdit->text();
    newLoginInfo+=",";
    newLoginInfo+=ui->PWEdit->text();
    qDebug()<<newLoginInfo;
    emit signal_loginInfo(newLoginInfo);
    ui->IDEdit->setText("");
    ui->PWEdit->setText("");
}


void LoginWidget::on_pushButton_2_clicked()
{

    emit signal_createAccount();
}

