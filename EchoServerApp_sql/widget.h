#ifndef WIDGET_H
#define WIDGET_H

#include <QLabel>
#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QSet>
#include "clientitem.h"
#include "clientmanagerform.h"
#include "databassethread.h"
#include "message.h"

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);

private slots:
    void clientConnect( );                       /* 에코 서버 */
    void echoData( );
    void clientDisconnect();
    void slot_login_check(QTcpSocket*,QString);
    void slot_return_friends(QList<QString>&,QTcpSocket*);
signals:
   void send_clientInfo(QString);
   void search_loginInfo(QTcpSocket*,QString,QString);
   void sig_get_friend(QString,QTcpSocket*);
   void sig_add_new_friend(QString,QString);
private:
    QList<ClientItem*> clientInfoList;
    QLabel *infoLabel;
    QTcpServer *tcpServer;
    QSet<QTcpSocket *> socketList;
    QMap<QTcpSocket *,QString> curruserList;
    QList<QString> clientIdList;
    QMap<QString,QString> m_chatList;
    QMap<QMap<int,QString>,QSet<QString>> roomPortList; //qmap<qmap<roomtype, roomport>,id_in_room>
    //ClientManagerForm* m_clientManager;
    DataBasseThread * dbThread;
     Message* newMsg;
     void msgProcess(QTcpSocket *clientConnection,QByteArray bytearray);
};

#endif // WIDGET_H
