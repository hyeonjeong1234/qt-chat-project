#ifndef MSGDATABASE_H
#define MSGDATABASE_H
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

class MsgDataBase: public QThread
{
    Q_OBJECT
public:
     explicit MsgDataBase(QObject *obj = nullptr);
     ~MsgDataBase();

//public:
//     void run() override;
//    void inputMsg( );
//    void addMsg(ClientItem*);
//    void deleteMsg(QString);
//    void modifyMsg(int);
//    int contain(QString id);
//    //makeId에서 makeNum으로 변경
//    int makeNum();
//    vector<QString> parseCSV(istream&, char);
//    //static bool createConnection( );
//    void showMsg();
//    void printMsg(QSqlTableModel*, int, int);
//    void insertMsg(QSqlTableModel*, int, const QString&, const QString&, const QString&, const QString&, const QString&);
//    //void insertData(QSqlTableModel &model, int num, const QString &id, const QString &pw, const QString &name, const QString &phone, const QString &address);
//public slots:
//    void process();

//signals:
//    void finished();
//    void error(QString err);
//    void result_login(QTcpSocket*,QString);
//private slots:
//    void receive_clientInfo(QString);

//private:
//    //QTableView *tableview;
//    QSqlTableModel *cMsgModel;
//    QMap<QString, ClientItem*> MSGList;
//    QMenu* menu;
    //ClientItem* search(QString);
};

#endif // MSGDATABASE_H
