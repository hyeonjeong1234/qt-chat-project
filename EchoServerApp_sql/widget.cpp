#include <QtGui>
#include <QtWidgets>
#include <QtNetwork>
#include <QDebug>
#include <QThread>
#include <QJsonDocument>
#include <QJsonObject>

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
        QJsonObject json;
            json["msgtype"] = 11;
            json["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODate);
            json["msgport"] = " ";  // 추가 필드 예시
            json["sendcli"] = " "; // 읽음 여부 추가
            json["msgcontext"] = "[Notice] 회원이 로그아웃 하셨습니다.";

        QString str = QString(QJsonDocument(json).toJson(QJsonDocument::Compact));
        QByteArray lengthPrefix;
        QDataStream stream(&lengthPrefix, QIODevice::WriteOnly);
        stream.setByteOrder(QDataStream::BigEndian); // 네트워크 전송 표준
        stream << static_cast<qint32>(str.size());        if(str.length()) {
            QByteArray bytearray;
            bytearray = lengthPrefix+str.toUtf8();
            //bytearray.append("\r\n");
            otherClient->write(bytearray);
        }
        infoLabel->setText(str);

    }

}

void Widget::echoData( )
{

    QTcpSocket *clientConnection = (QTcpSocket *)sender();
    QByteArray buffer;
    buffer.append(clientConnection->readAll());

    // 최소한 4바이트(길이 정보)가 있어야 함
    if (buffer.size() < 4) return;

    // 4바이트 길이 읽기
    QDataStream stream(&buffer, QIODevice::ReadOnly);
    stream.setByteOrder(QDataStream::BigEndian);
    qint32 jsonLength;
    stream >> jsonLength;

    // JSON 길이만큼 데이터가 도착했는지 확인
    if (buffer.size() < jsonLength + 4) return;

    // JSON 데이터 추출
    QByteArray jsonData = buffer.mid(4, jsonLength);
    buffer.remove(0, jsonLength + 4); // 처리한 데이터 제거

    // JSON 변환
    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);
    if (parseError.error == QJsonParseError::NoError) {
        QJsonObject jsonObj = jsonDoc.object();
        qDebug() << "Received JSON:" << jsonObj;
        msgProcess(clientConnection, jsonObj);  // 메시지 처리
    }
}

void Widget::msgProcess(QTcpSocket *clientConnection,QJsonObject json)
{
   // QString stringmsg = QString(bytearray);
    qDebug()<<"msgProcess STart!";
    //Json변환

    newMsg->setMsgType(json["msgtype"].toInt());
    newMsg->setMsgNum(json["timestamp"].toString());
    newMsg->setMsgPort(json["msgport"].toString());
    newMsg->setMsgSendCLi(json["sendcli"].toString());
    newMsg->setMsgContext(json["msgcontext"].toString());

    QStringList sepContext = newMsg->getMsgContext().split(',');

    qDebug()<<json;

    if(newMsg->getMsgType() == 0){
        qDebug()<<newMsg->getMsgContext();
            QList<QString> splitClientInfo = {sepContext[0],sepContext[1],sepContext[2],sepContext[3],sepContext[4]};
            ClientItem *newClientInfo = new ClientItem;
            newClientInfo->setClientName(splitClientInfo[0]);
            newClientInfo->setClientId(splitClientInfo[1]);
            newClientInfo->setClientPw(splitClientInfo[2]);
            newClientInfo->setClientPhoneNum(splitClientInfo[3]);
            newClientInfo->setClientAddress(splitClientInfo[4]);
            clientInfoList.append(newClientInfo);
            qDebug()<<newClientInfo->getClientName()<<","<<newClientInfo->getClientId()<<","<<newClientInfo->getClientPw()<<","<<newClientInfo->getClientPhoneNum()<<","<<newClientInfo->getClientAddress();

            QJsonObject json;
                json["msgtype"] = 0;
                json["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODate);
                json["msgport"] = "NEWCLI";  // 추가 필드 예시
                json["sendcli"] = splitClientInfo[1]; // 읽음 여부 추가
                json["msgcontext"] = "Y";

            QString str = QString(QJsonDocument(json).toJson(QJsonDocument::Compact));
            QByteArray lengthPrefix;
            QDataStream stream(&lengthPrefix, QIODevice::WriteOnly);
            stream.setByteOrder(QDataStream::BigEndian); // 네트워크 전송 표준
            stream << static_cast<qint32>(str.size());            if(str.length()) {
                QByteArray bytearray;
                bytearray = lengthPrefix+str.toUtf8();
                //bytearray.append("\r\n");
                clientConnection->write(bytearray);
            }
            infoLabel->setText(str);
            //회원가입시 내용파일에 저장필요splitArray
            clientIdList.append(splitClientInfo[1]);
            qDebug()<<"MsgCOntext!!"+newMsg->getMsgContext();
            emit send_clientInfo(newMsg->getMsgContext());
    }

    else if (newMsg->getMsgType() == 2)
    {
        QJsonObject json;
            json["msgtype"] = 2;
            json["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODate);
            json["msgport"] = newMsg->getMsgPort();  // 추가 필드 예시
            json["sendcli"] = newMsg->getMsgSendCli(); // 읽음 여부 추가
            json["msgcontext"] = newMsg->getMsgContext();

        QString str = QString(QJsonDocument(json).toJson(QJsonDocument::Compact));
        QByteArray lengthPrefix;
        QDataStream stream(&lengthPrefix, QIODevice::WriteOnly);
        stream.setByteOrder(QDataStream::BigEndian); // 네트워크 전송 표준
        stream << static_cast<qint32>(str.size());
        QList<QByteArray> splitport = newMsg->getMsgPort().toUtf8().split(':');
        foreach(QTcpSocket * otherClient,socketList)
        {
            if((otherClient!=clientConnection))
            {
                if(splitport.indexOf(curruserList[otherClient].toUtf8())!=-1)
                {
                    if(str.length()) {
                        QByteArray bytearray;
                        bytearray = lengthPrefix+str.toUtf8();
                        //bytearray.append("\r\n");
                        otherClient->write(bytearray);
                        infoLabel->setText(str);
                    }
                }

            }
            else
                continue;
        }
    }
    else if(newMsg->getMsgType() == 3)
    {
        qDebug()<<"cur port : "<<newMsg->getMsgPort()<<"msg:"<<newMsg->getMsgContext();
        int result = dbThread->contain(newMsg->getMsgContext());
        QByteArray str_result;
        if(result ==0)
        {
            str_result = "N";
        }
        else
        {
            str_result = "Y";
        }

        QJsonObject json;
            json["msgtype"] = 3;
            json["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODate);
            json["msgport"] = "Search";  // 추가 필드 예시
            json["sendcli"] = newMsg->getMsgSendCli(); // 읽음 여부 추가
            json["msgcontext"] = str_result+","+newMsg->getMsgContext();

        QString str = QString(QJsonDocument(json).toJson(QJsonDocument::Compact));
        QByteArray lengthPrefix;
        QDataStream stream(&lengthPrefix, QIODevice::WriteOnly);
        stream.setByteOrder(QDataStream::BigEndian); // 네트워크 전송 표준
        stream << static_cast<qint32>(str.size());        if(str.length()) {
            QByteArray bytearray;
            bytearray = lengthPrefix+str.toUtf8();
            //bytearray.append("\r\n");
            clientConnection->write(bytearray);
        }
        infoLabel->setText(str);

    }
    else if(newMsg->getMsgType()==1)
    {

        curruserList[clientConnection] = sepContext[0];
        emit search_loginInfo(clientConnection,sepContext[0],sepContext[1]);

    }
    else if(newMsg->getMsgType()== 4)
    {
       QList<QByteArray> people = newMsg->getMsgContext().toUtf8().split(':');
       QString a = QString(people[1])+":"+QString(people[0]);

       if((m_chatList.find(QString(newMsg->getMsgContext()))==m_chatList.end())&&(m_chatList.find(a)==m_chatList.end()))
       {
           m_chatList.insert(newMsg->getMsgContext(),a);

           foreach(QTcpSocket * otherClient,socketList)
           {
               int check = people.indexOf(curruserList[otherClient].toUtf8());
               if(check!=-1)
               {
                   QByteArray bytearray("10,,,,[Notice]"+people[check]+"님이 입장 하셨습니다.");

                   QJsonObject json;
                       json["msgtype"] = 10;
                       json["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODate);
                       json["msgport"] = " ";  // 추가 필드 예시
                       json["sendcli"] = " "; // 읽음 여부 추가
                       json["msgcontext"] = QString("[Notice]"+people[check]+"님이 입장 하셨습니다.");

                   QString str = QString(QJsonDocument(json).toJson(QJsonDocument::Compact));
                   QByteArray lengthPrefix;
                   QDataStream stream(&lengthPrefix, QIODevice::WriteOnly);
                   stream.setByteOrder(QDataStream::BigEndian); // 네트워크 전송 표준
                   stream << static_cast<qint32>(str.size());                   if(str.length()) {
                       QByteArray bytearray;
                       bytearray = lengthPrefix+str.toUtf8();
                       //bytearray.append("\r\n");
                       clientConnection->write(bytearray);
                   }
                   infoLabel->setText(str);
               }

           }
       }
    }
    else if(newMsg->getMsgType()== 5)
    {
        emit sig_add_new_friend(newMsg->getMsgSendCli(), newMsg->getMsgContext());
    }
    else
    {
        qDebug()<<"msgType : "<<newMsg->getMsgType();
    }
}

void Widget::slot_login_check(QTcpSocket* sendSocket,QString result)
{
    if(result=="Y")
    {
        QJsonObject json;
            json["msgtype"] = 1;
            json["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODate);
            json["msgport"] = "LOGIN";  // 추가 필드 예시
            json["sendcli"] = curruserList[sendSocket]; // 읽음 여부 추가
            json["msgcontext"] = "Y";

        QString str = QString(QJsonDocument(json).toJson(QJsonDocument::Compact));
        QByteArray lengthPrefix;
        QDataStream stream(&lengthPrefix, QIODevice::WriteOnly);
        stream.setByteOrder(QDataStream::BigEndian); // 네트워크 전송 표준
        stream << static_cast<qint32>(str.size());        if(str.length()) {
            QByteArray bytearray;
            bytearray = lengthPrefix+str.toUtf8();
            //bytearray.append("\r\n");
           sendSocket->write(bytearray);
        }
        infoLabel->setText(str);
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

        QJsonObject json;
            json["msgtype"] = 5;
            json["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODate);
            json["msgport"] = "FriendList";  // 추가 필드 예시
            json["sendcli"] = " "; // 읽음 여부 추가
            json["msgcontext"] = QString(a);

        QString str = QString(QJsonDocument(json).toJson(QJsonDocument::Compact));
        QByteArray lengthPrefix;
        QDataStream stream(&lengthPrefix, QIODevice::WriteOnly);
        stream.setByteOrder(QDataStream::BigEndian); // 네트워크 전송 표준
        stream << static_cast<qint32>(str.size());        if(str.length()) {
            QByteArray bytearray;
            bytearray = lengthPrefix+str.toUtf8();
            //bytearray.append("\r\n");
            socket->write(bytearray);
        }
        infoLabel->setText(str);
    }
}
