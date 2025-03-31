#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>
#include <QMouseEvent>

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
    ~ChatWidget();

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
    //void slot_presentMsg(QString sendCli,QString sendMsg);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void signal_newMsg(QString);
private:
    Ui::ChatWidget *ui;

    QPoint m_dragPosition;
};

#endif // CHATWIDGET_H
