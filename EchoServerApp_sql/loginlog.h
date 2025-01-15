#ifndef LOGINLOG_H
#define LOGINLOG_H


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
class LoginLog: public QThread
{
    Q_OBJECT
public:
      explicit LoginLog(QObject *obj = nullptr);
     ~LoginLog();

public:
     void run() override;
//    //void inputClient( );
//    void addlog(ClientItem*);
//    void deletelog(QString);
//    void modifylog(int);
//    int contain(QString id);
//    //makeId에서 makeNum으로 변경
//    int makeNum();
//    vector<QString> parseCSV(istream&, char);
//    //static bool createConnection( );
//    void showClient();
//    void printlog(QSqlTableModel*, int, int);
//    void insertlog(QSqlTableModel*, int, const QString&, const QString&, const QString&, const QString&, const QString&);
//    //void insertData(QSqlTableModel &model, int num, const QString &id, const QString &pw, const QString &name, const QString &phone, const QString &address);
//public slots:
//    void process();
//    void slot_search_loginInfo(QTcpSocket*,QString,QString);
//signals:
//    void finished();
//    void error(QString err);
//    void result_login(QTcpSocket*,QString);
//private slots:
//    void receive_log(QString);

//private:
//    //QTableView *tableview;
//    QSqlTableModel *clientModel;
//    QMap<QString, ClientItem*> clientList;
//    QMenu* menu;
//    ClientItem* search(QString);

};

#endif // LOGINLOG_H
