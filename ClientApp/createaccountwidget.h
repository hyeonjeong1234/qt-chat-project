#ifndef CREATEACCOUNTWIDGET_H
#define CREATEACCOUNTWIDGET_H

#include <QWidget>

namespace Ui {
class CreateAccountWidget;
}

class CreateAccountWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CreateAccountWidget(QWidget *parent = nullptr);
    ~CreateAccountWidget();

private:
    Ui::CreateAccountWidget *ui;

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

signals:
    void signal_delete();
    void sendClientInfo(QString);
};

#endif // CREATEACCOUNTWIDGET_H
