#include "createaccountwidget.h"
#include "ui_createaccountwidget.h"
#include <QDebug>
#include <QStyle>
#include <QDesktopWidget>
CreateAccountWidget::CreateAccountWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateAccountWidget)
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

CreateAccountWidget::~CreateAccountWidget()
{
    delete ui;
}


void CreateAccountWidget::on_pushButton_2_clicked()
{
    this->hide();
    emit signal_delete();
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
}


void CreateAccountWidget::on_pushButton_clicked()
{
   QString newClientInfo;
   newClientInfo =  ui->lineEdit->text();
   newClientInfo.append(",");
   newClientInfo.append(ui->lineEdit_2->text());
   newClientInfo.append(",");
   newClientInfo.append(ui->lineEdit_3->text());
   newClientInfo.append(",");
   newClientInfo.append(ui->lineEdit_4->text());
   newClientInfo.append(",");
   newClientInfo.append(ui->lineEdit_5->text());
   emit sendClientInfo(newClientInfo);
   qDebug()<<newClientInfo;
   ui->lineEdit->setText("");
   ui->lineEdit_2->setText("");
   ui->lineEdit_3->setText("");
   ui->lineEdit_4->setText("");
   ui->lineEdit_5->setText("");

}

