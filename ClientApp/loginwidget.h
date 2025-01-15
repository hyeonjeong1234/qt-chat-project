#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

private:
    Ui::LoginWidget *ui;

signals:
    void signal_loginInfo(QString ID);
    void  signal_createAccount();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

};

#endif // LOGINWIDGET_H
