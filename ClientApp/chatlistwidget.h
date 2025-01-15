#ifndef CHATLISTWIDGET_H
#define CHATLISTWIDGET_H

#include <QWidget>
#include <QListWidgetItem>
namespace Ui {
class ChatListWidget;
}

class ChatListWidget : public QWidget
{
    Q_OBJECT

public:
     ChatListWidget(QWidget *parent = nullptr);
    ~ChatListWidget();
     void addchatroom(QString addroomname);

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

signals:
    void click_chatroom(QString);
    void click_search(QString);
    void make_groupchat();


private:
    Ui::ChatListWidget *ui;
};

#endif // CHATLISTWIDGET_H
