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
    ~ChatWidget();
private slots:
    //void slot_presentMsg(QString sendCli,QString sendMsg);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void signal_newMsg(QString);
private:
    Ui::ChatWidget *ui;
};

#endif // CHATWIDGET_H
