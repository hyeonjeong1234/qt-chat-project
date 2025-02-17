#include <QtGui>
#include <QtWidgets>
#include <QtNetwork>
#include <QDebug>
#include <QThread>
#include "widget.h"

#define BLOCK_SIZE      1024
#define TCP_PORT        12345
Widget::Widget(QWidget *parent) : QWidget(parent)
{
    infoLabel = new QLabel(this);
    QPushButton* quitButton = new QPushButton("Quit", this);
    connect(quitButton, SIGNAL(clicked( )), qApp, SLOT(quit( )));

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(quitButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(infoLabel);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);
    tcpServer = new QTcpServer(this);
    if (!tcpServer ->listen(QHostAddress::Any,TCP_PORT)) {
        QMessageBox::critical(this, tr("Echo Server"), \
                              tr("Unable to start the server: %1.") \
                              .arg(tcpServer->errorString( )));
        close( );
        return;
    }
    connect(tcpServer, SIGNAL(newConnection( )), SLOT(clientConnect( )));
    infoLabel->setText(tr("The server is running on port %1.")
                                    .arg(tcpServer->serverPort( )));
    setWindowTitle(tr("Echo Server"));
    //m_clientManager = new ClientManagerForm();
    //m_clientManager->show();
    dbThread = new DataBasseThread();
    dbThread->start();
    newMsg = new Message();

    connect(this, SIGNAL(send_clientInfo(QString)),dbThread,SLOT(receive_clientInfo(QString)));
    connect(dbThread,SIGNAL(result_login(QTcpSocket*,QString)),this,SLOT(slot_login_check(QTcpSocket*,QString)));
    connect(this,SIGNAL(search_loginInfo(QTcpSocket*,QString,QString)),dbThread,SLOT(slot_search_loginInfo(QTcpSocket*,QString,QString)));
    connect(this,SIGNAL(sig_get_friend(QString,QTcpSocket*)), dbThread,SLOT(get_friend_list(QString,QTcpSocket*)));
    connect(dbThread,SIGNAL(return_friends(QList<QString>&,QTcpSocket*)),this,SLOT(slot_return_friends(QList<QString>&,QTcpSocket*)));
    connect(this, SIGNAL(sig_add_new_friend(QString,QString)),dbThread,SLOT(slot_get_new_friend(QString,QString)));
}

void Widget::clientConnect( )
{
    QTcpSocket *clientConnection = tcpServer->nextPendingConnection( );
    socketList.insert(clientConnection);
    curruserList.insert(clientConnection,"");
    connect(clientConnection, SIGNAL(readyRead( )), SLOT(echoData( )));
    connect(clientConnection, SIGNAL(disconnected( )), \
                 this, SLOT(clientDisconnect( )));
    infoLabel->setText("new connection is established...");

}

void Widget::clientDisconnect()
{
    QTcpSocket *clientDisconnection = (QTcpSocket*)sender();
    socketList.remove(clientDisconnection);
    curruserList.remove(clientDisconnection);
    foreach(QTcpSocket * otherClient,socketList)
    {
        QByteArray bytearray("11,,,,[Notice] 회원이 퇴장 하셨습니다.");//마지막 사람 나갔을 때도 서버로 알림 보내기
        bytearray.append("\r\n");
        otherClient->write(bytearray);
        infoLabel->setText(QString(bytearray));

    }

}

void Widget::echoData( )
{
    QTcpSocket *clientConnection = (QTcpSocket *)sender( );
    QByteArray buffer;
    buffer.append(clientConnection->readAll());
    while (buffer.contains("\r\n")) { // 종료 문자가 있는 동안 반복
           int endIndex = buffer.indexOf("\r\n"); // 메시지 끝 위치 찾기
           QByteArray message = buffer.left(endIndex); // 메시지 추출
           buffer.remove(0, endIndex + 2); // 처리한 메시지와 종료 문자 제거
           qDebug()<<message;
           msgProcess(clientConnection, message); // 메시지 처리
       }

}
void Widget::msgProcess(QTcpSocket *clientConnection,QByteArray bytearray)
{
    QString stringmsg = QString(bytearray);
    qDebug()<<bytearray;
     QList<QString> splitArray = stringmsg.split(',');

     newMsg->setMsgType(splitArray[0].toInt());
     newMsg->setMsgPort(splitArray[2]);
     newMsg->setMsgSendCLi(splitArray[3]);
     QString context;
     for(int i = 4; i<splitArray.length();i++)
     {

         if(i == 4){
             context =splitArray[i];
         }
         else
         {
             context+=",";
             context+=splitArray[i];
         }
     }
     newMsg->setMsgContext(context);
    if(bytearray.front() == '0'){
        qDebug()<<splitArray[4];
            QList<QString> splitClientInfo = {splitArray[4],splitArray[5],splitArray[6],splitArray[7],splitArray[8]};
            ClientItem *newClientInfo = new ClientItem;
            newClientInfo->setClientName(splitClientInfo[0]);
            newClientInfo->setClientId(splitClientInfo[1]);
            newClientInfo->setClientPw(splitClientInfo[2]);
            newClientInfo->setClientPhoneNum(splitClientInfo[3]);
            newClientInfo->setClientAddress(splitClientInfo[4]);
            clientInfoList.append(newClientInfo);
            qDebug()<<newClientInfo->getClientName()<<","<<newClientInfo->getClientId()<<","<<newClientInfo->getClientPw()<<","<<newClientInfo->getClientPhoneNum()<<","<<newClientInfo->getClientAddress();
            QByteArray bytearray("0,,NEWCLI,"+splitClientInfo[1].toUtf8()+",Y");
            bytearray.append("\r\n");
            clientConnection->write(bytearray);
            infoLabel->setText(QString(bytearray));
            //회원가입시 내용파일에 저장필요splitArray
            clientIdList.append(splitClientInfo[1]);
            emit send_clientInfo(stringmsg);
    }

    else if (bytearray[0] == '2')
    {
        QByteArray a ="2,,"+splitArray[2].toUtf8()+","+splitArray[3].toUtf8()+","+splitArray[4].toUtf8() ;
        qDebug()<<a;
        QList<QByteArray> splitport = splitArray[2].toUtf8().split(':');
        foreach(QTcpSocket * otherClient,socketList)
        {
            if((otherClient!=clientConnection))
            {
                if(splitport.indexOf(curruserList[otherClient].toUtf8())!=-1)
                {
                    a.append("\r\n");
                    otherClient->write(a);
                    infoLabel->setText(QString(bytearray));

                }

            }
            else
                continue;
        }
    }
    else if(bytearray[0] == '3')
    {
        qDebug()<<"cur port : "<<splitArray[2]<<"msg:"<<splitArray[4];
        int result = dbThread->contain(splitArray[4]);
        QByteArray str_result;
        if(result ==0)
        {
            str_result = "N";
        }
        else
        {
            str_result = "Y";
        }
        QByteArray a = "3,,Search,"+splitArray[3].toUtf8()+","+str_result+","+splitArray[4].toUtf8();
        a.append("\r\n");
        clientConnection->write(a);
        infoLabel->setText(QString(bytearray));//-1이면 실패

    }
    else if(bytearray[0]=='1')
    {

        curruserList[clientConnection] = splitArray[4];
        emit search_loginInfo(clientConnection,splitArray[4],splitArray[5]);

    }
    else if(bytearray[0] == '4')
    {
       QList<QByteArray> people = splitArray[4].toUtf8().split(':');
       QString a = QString(people[1])+":"+QString(people[0]);

       if((m_chatList.find(QString(splitArray[4]))==m_chatList.end())&&(m_chatList.find(a)==m_chatList.end()))
       {
           m_chatList.insert(splitArray[4],a);

           foreach(QTcpSocket * otherClient,socketList)
           {
               int check = people.indexOf(curruserList[otherClient].toUtf8());
               if(check!=-1)
               {
                   QByteArray bytearray("10,,,,[Notice]"+people[check]+"님이 입장 하셨습니다.");
                   bytearray.append("\r\n");
                   otherClient->write(bytearray);
                   infoLabel->setText(QString(bytearray));
               }

           }
       }
    }
    else if(bytearray[0] == '5')
    {
        emit sig_add_new_friend(newMsg->getMsgSendCli(), newMsg->getMsgContext());
    }
    else
    {
        qDebug()<<"msgType : "<<bytearray[0];
    }
}

void Widget::slot_login_check(QTcpSocket* sendSocket,QString result)
{
    if(result=="Y")
    {
        QByteArray a ="1,,LOGIN,"+curruserList[sendSocket].toUtf8()+",Y" ;
        //a.append(bytearray);
        //로그인하면 회원가입파일에서 아이디 찾아서 있으면 아이디 반환. 없으면 n반환 y반환했으면 curClient에 소켓이랑 아이디 저장
        a.append("\r\n");
       sendSocket->write(a);
        infoLabel->setText(QString(a));
    }
     if (sendSocket->waitForBytesWritten()) {
    QTimer::singleShot(0, this, [this, sendSocket] {
                   emit sig_get_friend(curruserList[sendSocket].toUtf8(), sendSocket);
               });
     }
   //emit sig_get_friend(curruserList[sendSocket].toUtf8(),sendSocket);
}
void Widget::slot_return_friends(QList<QString>& friends,QTcpSocket* socket)
{
    QByteArray a = "";
    if(friends.size() == 0||friends[0] == "\0")
    {
        //에러알림이나 그런거 띄우기 사이즈 0이면 친구없음 아니면 에러
    }
    else{
        for(int i = 0; i<friends.size();i++)
        {
            if(i !=0||i == friends.size())
                a.append(",");
            a.append(friends[i].toUtf8());
        }
        QByteArray msg = "5,,friendsList,,";
        a.insert(0,msg);
        a.append("\r\n");
        if(socket->write(a))
            qDebug()<<"Success!!!!!!!1";
        else
            qDebug()<<"failㅠㅠㅠㅠㅠㅠㅠㅠㅠ";
        infoLabel->setText(QString(a));
    }
}
