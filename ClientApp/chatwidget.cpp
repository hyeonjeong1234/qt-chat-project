#include "chatwidget.h"
#include "ui_chatwidget.h"

#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
ChatWidget::ChatWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatWidget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
}

ChatWidget::~ChatWidget()
{
    delete ui;
}
void ChatWidget::setText(QString sendCli,QString sendMsg)//바꿀필요있을듯!!!!!!!!!!1
{
    QList<QString> checkme = sendMsg.split(':');
    QString msg;
    msg = sendMsg.remove(0,checkme[0].size()+1);
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
    QString msg;
    msg = ui->textEdit_2->toPlainText();
    qDebug()<< msg;
    ui->textEdit_2->setText("");
    return msg;
}
void ChatWidget::on_pushButton_clicked()
{
    //QString newMsg = ui->textEdit->text();
    emit signal_newMsg(this->windowTitle());
}


void ChatWidget::on_pushButton_2_clicked()
{
    this->hide();
}

void ChatWidget::setChatroomName(QString friendName)
{
    ui->label_2->setText(friendName);
}

void ChatWidget::paintEvent(QPaintEvent *event) //위젯이나 다이얼로그의 테두리 그리기
{
    QPainter painter(this);  // 현재 위젯을 대상으로 QPainter 사용
       painter.setRenderHint(QPainter::Antialiasing);  // 곡선을 부드럽게

       int radius = 10;  // 둥근 모서리의 반지름
       painter.setPen(Qt::NoPen);   // 검은색 테두리
       painter.setBrush(QColor(116, 88, 80));  // 연한 파란색 배경

       // 모서리를 둥글게 설정 (반지름 15)
       painter.drawRoundedRect(0, 0, width()-1, height()-1, radius, radius);

       QWidget::paintEvent(event);  // 기본 위젯 이벤트 호출
}
