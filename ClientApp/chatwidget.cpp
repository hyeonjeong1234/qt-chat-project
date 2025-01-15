#include "chatwidget.h"
#include "ui_chatwidget.h"


ChatWidget::ChatWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatWidget)
{
    ui->setupUi(this);
}

ChatWidget::~ChatWidget()
{
    delete ui;
}
void ChatWidget::setText(QString sendCli,QString sendMsg)
{
    QList<QString> checkme = sendMsg.split(':');
    QString msg;
    for(int i = 1; i<checkme.length();i++)
    {
        msg += checkme[i];
    }
    if(checkme[0] == "me")
    {
        ui->textEdit->append(sendCli+": "+msg);
        QTextCursor cursor = ui->textEdit->textCursor();
        QTextBlockFormat textBlockFormat = cursor.blockFormat();
        textBlockFormat.setAlignment(Qt::AlignRight);
        cursor.mergeBlockFormat(textBlockFormat);
        ui->textEdit->setTextCursor(cursor);
    }
    else{
    ui->textEdit->append(sendCli+": "+msg);
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextBlockFormat textBlockFormat = cursor.blockFormat();
    textBlockFormat.setAlignment(Qt::AlignLeft);
    cursor.mergeBlockFormat(textBlockFormat);
    ui->textEdit->setTextCursor(cursor);
    }



}
QString ChatWidget::getText()
{
    QString msg = ui->lineEdit->text();
    ui->lineEdit->setText("");
    return msg;
}
void ChatWidget::on_pushButton_clicked()
{
    //QString newMsg = ui->lineEdit->text();
    emit signal_newMsg();
}


void ChatWidget::on_pushButton_2_clicked()
{
    this->hide();
}

