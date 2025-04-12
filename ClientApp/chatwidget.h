#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>

namespace Ui {
class ChatWidget;
}

class ChatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChatWidget(QWidget *parent = nullptr);
    void setText(QString sendCli,QString sendMsg);
    QString getText();
    void setChatroomName(QString);
       void setContent(QWidget *widget);
    ~ChatWidget();

protected:
       void mousePressEvent(QMouseEvent *event) override;
          void mouseReleaseEvent(QMouseEvent *event) override;
          void mouseMoveEvent(QMouseEvent *event) override;
          void mouseDoubleClickEvent(QMouseEvent *event) override;
          void updateCursorShape(const QPoint &pos);
          void paintEvent(QPaintEvent *event) override;
private slots:
    //void slot_presentMsg(QString sendCli,QString sendMsg);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void signal_newMsg(QString);
private:
    Ui::ChatWidget *ui;

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

#endif // CHATWIDGET_H
