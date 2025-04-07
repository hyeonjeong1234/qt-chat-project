#include "chatlistwidget.h"
#include "ui_chatlistwidget.h"

#include <QPainter>
#include <QPaintEvent>


ChatListWidget::ChatListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatListWidget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
}

ChatListWidget::~ChatListWidget()
{
    delete ui;
}

void ChatListWidget::on_listWidget_itemClicked(QListWidgetItem *item)
{
    emit click_chatroom(item->text());
}


void ChatListWidget::on_pushButton_3_clicked()
{
    QString search_Id = ui->lineEdit_3->text();
    emit click_search(search_Id);

}

void ChatListWidget::addchatroom(QString addroomname)
{

    QListWidgetItem *pItem=new QListWidgetItem;
    pItem->setText(addroomname);
    QFont font = QFont("Ubuntu");
    font.setStyleHint (QFont::Monospace);
    font.setPointSize (20);
    font.setFixedPitch (true);
    pItem->setFont (font);
    ui->listWidget->addItem(pItem);


}

void ChatListWidget::on_pushButton_clicked()
{
    emit make_groupchat();
}

void ChatListWidget::paintEvent(QPaintEvent *event) //위젯이나 다이얼로그의 테두리 그리기
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
