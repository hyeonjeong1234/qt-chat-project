#ifndef DATABASSETHREAD_H
#define DATABASSETHREAD_H
#include <QThread>
#include <QHash>

//QSqlDatabase 헤더파일
#include <QApplication>
#include <QTableView>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTcpSocket>
#include "clientitem.h"
class DataBasseThread: public QThread
{
    Q_OBJECT
public:
     explicit DataBasseThread(QObject *obj = nullptr);
     ~DataBasseThread();

public:
     void run() override;
    void inputClient( );
    void addClient(ClientItem*);
    void deleteClient(QString);
    void modifyClient(int);
    int contain(QString id);
    //makeId에서 makeNum으로 변경
    int makeNum();
    vector<QString> parseCSV(istream&, char);
    //static bool createConnection( );
    void showClient();
    void printData(QSqlTableModel*, int, int);
    void insertData(QSqlTableModel*, int, const QString&, const QString&, const QString&, const QString&, const QString&);
    void get_message(QString msgport ,QString timestamp ,QTcpSocket* socket);
    //void insertData(QSqlTableModel &model, int num, const QString &id, const QString &pw, const QString &name, const QString &phone, const QString &address);
public slots:
    void process();
    void slot_search_loginInfo(QTcpSocket*,QString,QString);
    void get_friend_list(QString userId,QTcpSocket*);
    void slot_get_new_friend(QString,QString);
signals:
    void finished();
    void error(QString err);
    void result_login(QTcpSocket*,QString);
    void return_friends(QList<QString>&,QTcpSocket*);
private slots:
    void receive_clientInfo(QString);

private:
    //QTableView *tableview;
    QSqlTableModel *clientModel;
    QMap<QString, ClientItem*> clientList;
    QMenu* menu;
    ClientItem* search(QString);

};

#endif // DATABASSETHREAD_H
