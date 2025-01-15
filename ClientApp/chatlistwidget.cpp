#include "chatlistwidget.h"
#include "ui_chatlistwidget.h"

ChatListWidget::ChatListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatListWidget)
{
    ui->setupUi(this);


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

