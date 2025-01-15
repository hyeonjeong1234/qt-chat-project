#ifndef CLIENTMANAGERFORM_H
#define CLIENTMANAGERFORM_H

#include <QWidget>
#include <QHash>

//QSqlDatabase 헤더파일
#include <QApplication>
#include <QTableView>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>

#include "clientitem.h"

class QMenu;
class QListWidgetItem;

namespace Ui {
class ClientManagerForm;
}


class ClientManagerForm : public QWidget
{
    Q_OBJECT

public:
    explicit ClientManagerForm(QWidget *parent = nullptr);
    ~ClientManagerForm();

    void inputClient( );
    void addClient(ClientItem*);
    void deleteClient(int);
    ClientItem* search(int);
    //makeId에서 makeNum으로 변경
    int makeNum();
    vector<QString> parseCSV(istream&, char);
    //static bool createConnection( );
    void showClient();
    void printData(QSqlTableModel*, int, int);
    void insertData(QSqlTableModel*, int, const QString&, const QString&, const QString&, const QString&, const QString&);
    //void insertData(QSqlTableModel &model, int num, const QString &id, const QString &pw, const QString &name, const QString &phone, const QString &address);

private slots:
    void on_pushButton_clicked();
    void removeItem();
    void showContextMenu(const QPoint &);

    void on_pushButton_3_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButtonModify_clicked();

private:
    //QTableView *tableview;
    QSqlTableModel *clientModel;
    QMap<int, ClientItem*> clientList;
    Ui::ClientManagerForm *ui;
    QMenu* menu;
};

#endif // CLIENTMANAGERFORM_H
