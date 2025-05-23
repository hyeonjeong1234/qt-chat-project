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

protected:
     void mousePressEvent(QMouseEvent *event) override;
        void mouseReleaseEvent(QMouseEvent *event) override;
        void mouseMoveEvent(QMouseEvent *event) override;
        void mouseDoubleClickEvent(QMouseEvent *event) override;
        void updateCursorShape(const QPoint &pos);
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
    enum ResizeRegion {
           None,
           Left,
           Right,
           Top,
           Bottom,
           TopLeft,
           TopRight,
           BottomLeft,
           BottomRight
       };

       ResizeRegion getResizeRegion(const QPoint &pos);
       ResizeRegion currentRegion = None;

       bool resizing = false;
       QPoint dragStartPos;
       QRect originalGeometry;

       const int resizeMargin = 8;
       bool dragging = false;
       bool maximized = false;
       QRect normalGeometry;

};

#endif // CHATLISTWIDGET_H
