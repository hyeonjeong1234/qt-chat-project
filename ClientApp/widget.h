#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QTcpSocket>
#include "loginwidget.h"
#include "createaccountwidget.h"
#include "message.h"
#include "myinfo.h"
#include "chatlistwidget.h"
#include "chatwidget.h"
#include "searchid.h"
#include <QTabWidget>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
     void after_search(QString searchId);
     void afterLogin();
private slots:
    void echoData( );
    void sendData();
    void slot_loginInfo(QString name);
    void makeConnection();
    void slot_createAccount();
    void slot_creatAccDel();
    void connectError();
    void recvClientInfo(QString);
    void slot_click_chatroom(QString chatroom);
    void slot_click_search(QString search_Id);
    void slot_newFriend(QString newFriend);
    void slot_makegroupchat();
signals:
    void sig_presentMsg(QString,QString);
    void signal_newFriend(QString);

private:
    Ui::Widget *ui;
    QTextEdit *message;
    QLineEdit *inputLine;
    QTcpSocket *clientSocket;
    LoginWidget *loginWidget;
    QString m_ID;
    QLineEdit* serverAddress;
    QLineEdit* serverPort;
    CreateAccountWidget* createAccWidget;
    Message *newMessaage;
    MyInfo *myInfo;
    ChatListWidget *chatList;
    ChatWidget *chatWidget;
    QMap<QString, ChatWidget *> joinChatList;
    SearchId* makeGroupChat;


};
#endif // WIDGET_H
