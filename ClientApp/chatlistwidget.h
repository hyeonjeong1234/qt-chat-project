#ifndef CHATLISTWIDGET_H
#define CHATLISTWIDGET_H

#include <QWidget>
#include <QListWidgetItem>
#include <QMouseEvent>
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

protected:
    void mousePressEvent(QMouseEvent *event) override {
           if (event->button() == Qt::LeftButton) {
               m_dragPosition = event->globalPos() - frameGeometry().topLeft();
               event->accept();
           }
       }

       void mouseMoveEvent(QMouseEvent *event) override {
           if (event->buttons() & Qt::LeftButton) {
               move(event->globalPos() - m_dragPosition);
               event->accept();
           }
       }
       void paintEvent(QPaintEvent *event) override;

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
    QPoint m_dragPosition;
};

#endif // CHATLISTWIDGET_H
