#include "widget.h"
#include "ui_widget.h"

#include <QtGui>
#include <QtWidgets>
#include <QtNetwork>
#include <QDebug>
#include <QMessageBox>
#include <QAbstractSocket>
#include <QStyle>
#include <QDesktopWidget>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDateTime>


#define BLOCK_SIZE      1024
#define TCP_PORT        12345


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry())
        );
    serverAddress = new QLineEdit(this);
    serverAddress->setText("127.0.0.1");
    //    serverAddress->setInputMask("999.999.999.999;_");
    QRegularExpression re("^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                          "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                          "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                          "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$|");
    QRegularExpressionValidator validator(re);
    serverAddress->setValidator(&validator);
    serverAddress->setPlaceholderText("Server IP Address");

    serverPort = new QLineEdit(this);
    serverPort->setInputMask("00000;_");
    serverPort->setPlaceholderText("Server Port No");

    QPushButton* connectButton = new QPushButton("connect", this);

    QHBoxLayout *serverLayout = new QHBoxLayout;
    serverLayout->addStretch(1);
    serverLayout->addWidget(serverAddress);
    serverLayout->addWidget(serverPort);
    serverLayout->addWidget(connectButton);

    message = new QTextEdit(this);
    message->setReadOnly(true);

    inputLine = new QLineEdit(this);
    QPushButton* sentButton = new QPushButton("Send", this);
    QHBoxLayout *inputLayout = new QHBoxLayout;
    inputLayout->addWidget(inputLine);
    inputLayout->addWidget(sentButton);

    QPushButton* quitButton = new QPushButton("Quit", this);
    connect(quitButton, SIGNAL(clicked( )), qApp, SLOT(quit( )));

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(quitButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(serverLayout);
    mainLayout->addWidget(message);
    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    chatList = new ChatListWidget();//채팅방리스트 창
    connect(chatList,SIGNAL(click_chatroom(QString)),this,SLOT(slot_click_chatroom(QString)));
    connect(chatList,SIGNAL(click_search(QString)),this,SLOT(slot_click_search(QString)));

    newMessaage = new Message();
    clientSocket = new QTcpSocket(this);
    makeConnection();
    //connect(connectButton, &QPushButton::clicked,this, &Widget::makeConnection);
    connect(clientSocket, &QAbstractSocket::errorOccurred,
           this,&Widget::connectError);
    connect(clientSocket, SIGNAL(readyRead( )), SLOT(echoData( )));
    //setWindowTitle(tr("Echo Client"));
    loginWidget = new LoginWidget();
    connect(loginWidget, &LoginWidget::signal_loginInfo, this, &Widget::slot_loginInfo);
    loginWidget->show();
    createAccWidget = new CreateAccountWidget();
    connect(loginWidget,&LoginWidget::signal_createAccount,this,&Widget::slot_createAccount);
    connect(createAccWidget,&CreateAccountWidget::signal_delete,this,&Widget::slot_creatAccDel);
    connect(createAccWidget,&CreateAccountWidget::sendClientInfo,this,&Widget::recvClientInfo);
    myInfo = new MyInfo();
     chatWidget =new ChatWidget();
     connect(this, SIGNAL(signal_newFriend(QString)),this,SLOT(slot_newFriend(QString)));
     makeGroupChat = new SearchId();
     connect(chatList,SIGNAL(make_groupchat()),this,SLOT(slot_makegroupchat()));
     connect(makeGroupChat,SIGNAL(clicked_search(QString)),this,SLOT());
}

Widget::~Widget()
{
    delete ui;

    clientSocket->close();
}

void Widget::echoData( )
{

    QTcpSocket *clientConnection = (QTcpSocket *)sender( );
    QByteArray buffer;
    buffer.append(clientConnection->readAll());
    while (buffer.size() >= 4) {  // 최소 4바이트(길이 정보)가 있어야 함
          bool ok;
          int jsonLength = buffer.left(4).toInt(&ok);
          if (!ok || buffer.size() < jsonLength + 4) return; // 데이터 부족

          // JSON 데이터만 추출
          QByteArray jsonData = buffer.mid(4, jsonLength);
          buffer.remove(0, jsonLength + 4); // 처리한 데이터 제거

          // JSON 변환
          QJsonParseError parseError;
          QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);
          if (parseError.error == QJsonParseError::NoError) {
              QJsonObject jsonObj = jsonDoc.object();
              qDebug() << "Received JSON:" << jsonObj;
              QString str = jsonObj["msgtype"].toVariant().toString()+","+jsonObj["timestamp"].toString()+","+jsonObj["msgport"].toString()+","+jsonObj["sendcli"].toString()+","+jsonObj["msgcontext"].toString();

              msgProcess(clientConnection, str.toUtf8());  // 메시지 처리
          }
      }


}

void Widget::msgProcess(QTcpSocket *clientConnection,  QByteArray bytearray)
{
    qDebug()<<"arrived Message : "<<bytearray;
    QStringList splitMessage = QString(bytearray).split(QLatin1Char(','));
    int splitSize = splitMessage.size();
    QList<QString> chatname = splitMessage[3].split(':');
    QString chatroom;
    QString newPort;
    if(splitSize >4){
        newMessaage->setMsgType(splitMessage[0].toInt());
        newMessaage->setMsgNum(splitMessage[1].toInt());
        newMessaage->setMsgPort(splitMessage[2]);
        newMessaage->setMsgSendCLi(splitMessage[3]);
        newMessaage->setMsgContext(splitMessage[4]);
      }
    else{
        while(splitMessage.length()<5)
        {
            splitMessage.append("");
        }
        newMessaage->setMsgType(splitMessage[0].toInt());
        newMessaage->setMsgNum(splitMessage[1].toInt());
        newMessaage->setMsgPort(splitMessage[2]);
        newMessaage->setMsgSendCLi(splitMessage[3]);
        newMessaage->setMsgContext(splitMessage[4]);
    }
    QStringList splitPort = newMessaage->getMsgPort().split(":");

    qDebug()<<"Type : "+splitMessage[0]+","+splitMessage[1]+","+splitMessage[2]+","+splitMessage[3]+","+"MESAGE: "+splitMessage[4];
       printf("newMEssage %d\n",newMessaage->getMsgType());

    switch (newMessaage->getMsgType())
    {
    case 0:
        qDebug()<<"MSG TYPE : "+QString(newMessaage->getMsgType())+"\n";
        if(newMessaage->getMsgContext() == "N")
        {

            QMessageBox connectError;
            connectError.setGeometry(
                QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    connectError.size(),
                    qApp->desktop()->availableGeometry())
                );
            QMessageBox::StandardButtons buttonCheck = QMessageBox::Ok;
            if(buttonCheck == connectError.warning(this,"Error : Fail Create Account","Try again after few minute",QMessageBox::Ok))
            {
               qDebug()<<"Error : Fail Create Account";
            }
        }
        else
        {
            qDebug()<<"SUCESS :: CREATE Account!";
            m_ID = splitMessage[3];
            myInfo->setMyId(m_ID);
            qDebug()<<"MY ID == "<<m_ID;
            createAccWidget->hide();
            loginWidget->show();
        }
        break;
    case 1:
        if(newMessaage->getMsgContext() == "N")
        {

            QMessageBox connectError;
            connectError.setGeometry(
                QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    connectError.size(),
                    qApp->desktop()->availableGeometry())
                );
            QMessageBox::StandardButtons buttonCheck = QMessageBox::Ok;
            if(buttonCheck == connectError.warning(this,"Error : Fail Sign In","Try again after few minute",QMessageBox::Ok))
            {
               qDebug()<<"Error : Fail Sign In";
            }
        }
        else
        {
            qDebug()<<"SUCESS :: Sign In!";
            myInfo->setMyId(splitMessage[3]);
            qDebug()<<"SEtMY ID : "<<myInfo->getMyId();
            loginWidget->hide();
            chatList->show();
            afterLogin();
        }
        break;
    case 2://채팅방 하나당 위젯 하나 생성->new? 맵에 저장해서 채팅방 이름 받아서 같은 채팅방 이름만 전송
        qDebug()<<"SEndID: "<<newMessaage->getMsgSendCli()<<"my_Id : "<<myInfo->getMyId();
        for(int i = 0; i<chatname.length();i++)
        {
            if(chatname[i] != newMessaage->getMsgSendCli())
            {
               chatroom = chatname[i];
            }
        }
        if(newMessaage->getMsgSendCli() != myInfo->getMyId())
        {
            if(splitPort.length()==2){
                if(joinChatList.find(newMessaage->getMsgSendCli())==joinChatList.end())
                {
                    emit signal_newFriend(newMessaage->getMsgSendCli());
                }
                else
                    joinChatList[newMessaage->getMsgSendCli()]->setText(newMessaage->getMsgSendCli(),"others:"+newMessaage->getMsgContext());

            }
            else
            {
                //단톡이면 방이름으로?
            }

        }

        //message->append();
        break;
    case 3:
        //검색 결과 서버로 부터 받은 yes no처리
        if(newMessaage->getMsgContext() == "N")
        {

            QMessageBox connectError;
            connectError.setGeometry(
                QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    connectError.size(),
                    qApp->desktop()->availableGeometry())
                );
            QMessageBox::StandardButtons buttonCheck = QMessageBox::Ok;
            if(buttonCheck == connectError.warning(this,"Error : NO Result","Check the spelling of the ID you want to search for",QMessageBox::Ok))
            {
               qDebug()<<"Error : not find ID";
            }
        }
        else
            after_search(splitMessage[5]);

        break;
    case 5:
        qDebug()<<"recevie friends list";
        for(int i = 4;i<splitMessage.size();i++)
        {
            chatWidget = new ChatWidget();
            newPort = myInfo->getMyId()+":"+splitMessage[i];
            myInfo->addNewPort(splitMessage[i],newPort);
            chatList->addchatroom(splitMessage[i]);
            joinChatList.insert(splitMessage[i],chatWidget);
            chatWidget->setWindowTitle(splitMessage[i]);
            chatWidget->setChatroomName(splitMessage[i]);
            connect(joinChatList[splitMessage[i]],SIGNAL(signal_newMsg(QString)),this,SLOT(sendData(QString)));
        }

        break;
    default:
        message->append(newMessaage->getMsgContext());
        QTextCursor cursor = message->textCursor();
        QTextBlockFormat textBlockFormat = cursor.blockFormat();
        textBlockFormat.setAlignment(Qt::AlignCenter);
        cursor.mergeBlockFormat(textBlockFormat);
        message->setTextCursor(cursor);
        break;
    }
}
void Widget::afterLogin()
{
    chatList->setWindowTitle(myInfo->getMyId());
}
void Widget::sendData(QString curport)
{
    myInfo->currentPort = myInfo->getMyId()+":"+curport;
    QStringList splitPort = myInfo->currentPort.split(':');
    QString currport;
    for(int i=0;i<2;i++)
    {
        if(splitPort[i]!=myInfo->getMyId())
            currport = splitPort[i];
    }
    QString forsend = joinChatList[currport]->getText();

    //JSON 문자열로 변환
    QJsonObject json;
        json["msgtype"] = 2;
        json["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODate);
        json["msgport"] = myInfo->currentPort;  // 추가 필드 예시
        json["sendcli"] = myInfo->getMyId(); // 읽음 여부 추가
        json["msgcontext"] = forsend;

    joinChatList[currport]->setText(myInfo->getMyId(),"me:"+forsend);

    QString str = QString(QJsonDocument(json).toJson(QJsonDocument::Compact));
    QByteArray lengthPrefix = QByteArray::number(str.size()).rightJustified(4, '0');
    if(str.length()) {
        QByteArray bytearray;
        bytearray = lengthPrefix+str.toUtf8();
        //bytearray.append("\r\n");
        clientSocket->write(bytearray);

    }
}
 void Widget::slot_loginInfo(QString name)//로그인 정보 전송
 {
     //this->show();
     QJsonObject json;
         json["msgtype"] = 1;
         json["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODate);
         json["msgport"] = "12345";  // 추가 필드 예시
         json["sendcli"] = "loginInfo"; // 읽음 여부 추가
         json["msgcontext"] = name;

     QString str = QString(QJsonDocument(json).toJson(QJsonDocument::Compact));
     QByteArray lengthPrefix = QByteArray::number(str.size()).rightJustified(4, '0');
     if(str.length()) {
         QByteArray bytearray;
         bytearray = lengthPrefix+str.toUtf8();
         //bytearray.append("\r\n");
         clientSocket->write(bytearray);
     }


 }
 void Widget::makeConnection()//서버와 연결시도
 {
    clientSocket->connectToHost(serverAddress->text(), TCP_PORT);

 }
 void Widget::slot_createAccount()//로그인화면에서 회원가입버튼 눌렀을 때
 {
     loginWidget->hide();
     createAccWidget->show();

 }
 void Widget::slot_creatAccDel()//회원가입창에서 딜리트누르면 로그인화면으로
{
     loginWidget->show();
 }

void Widget::connectError()//server와의 연결 실패시 알림 뜨고 확인누르면 프로그램 종료
{

    QMessageBox connectError;
    connectError.setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            connectError.size(),
            qApp->desktop()->availableGeometry())
        );
    QMessageBox::StandardButtons buttonCheck = QMessageBox::Ok;
    if(buttonCheck == connectError.warning(this,"Connection refused","Please run after few minute",QMessageBox::Ok))
    {
        qDebug()<<"Connection refused";
        this->close();
        createAccWidget->close();
        loginWidget->close();
        qApp->quit();
    }


}
void Widget::recvClientInfo( QString newClientInfo)//회원가입정보 ,로 구분해서 전송
{
    QList<QString> splitInfo = newClientInfo.split(',');
    m_ID = splitInfo[1];

    //전송하고 회원 정보 저장되면 서버에서 ok띄워주기->로그인창 띄워서 로그인하기

    QJsonObject json;
        json["msgtype"] = 0;
        json["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODate);
        json["msgport"] = " ";  // 추가 필드 예시
        json["sendcli"] = m_ID; // 읽음 여부 추가
        json["msgcontext"] = newClientInfo;

    QString str = QString(QJsonDocument(json).toJson(QJsonDocument::Compact));
    QByteArray lengthPrefix = QByteArray::number(str.size()).rightJustified(4, '0');
    if(str.length()) {
        QByteArray bytearray;
        bytearray = lengthPrefix+str.toUtf8();
        //bytearray.append("\r\n");
        clientSocket->write(bytearray);
    }

}
void Widget::slot_click_chatroom(QString chatroom)
{
    QString roomPort = myInfo->searchPort(chatroom);
    if(roomPort!="-1")
    {
        myInfo->currentPort = roomPort;
    }

    QJsonObject json;
        json["msgtype"] = 4;
        json["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODate);
        json["msgport"] = roomPort;  // 추가 필드 예시
        json["sendcli"] = myInfo->getMyId(); // 읽음 여부 추가
        json["msgcontext"] = roomPort;

    QString str = QString(QJsonDocument(json).toJson(QJsonDocument::Compact));
    QByteArray lengthPrefix = QByteArray::number(str.size()).rightJustified(4, '0');
    if(str.length()) {
        QByteArray bytearray;
        bytearray = lengthPrefix+str.toUtf8();
        //bytearray.append("\r\n");
        clientSocket->write(bytearray);
    }


    //chatList->hide();
    QStringList roomname = roomPort.split(':');
    QString currroom;
    for(int i = 0; i< roomname.length();i++)
    {
        if(roomname[i]!= myInfo->getMyId())
        {
            if(i<2)
            {
                currroom = roomname[i];
            }
        }
    }
    joinChatList[currroom]->show();

}
void Widget:: slot_click_search(QString search_Id)
{
    QString to_search = search_Id;
    QJsonObject json;
        json["msgtype"] = 3;
        json["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODate);
        json["msgport"] = "findPort";  // 추가 필드 예시
        json["sendcli"] = myInfo->getMyId(); // 읽음 여부 추가
        json["msgcontext"] = to_search;

    QString str = QString(QJsonDocument(json).toJson(QJsonDocument::Compact));
    QByteArray lengthPrefix = QByteArray::number(str.size()).rightJustified(4, '0');
    if(str.length()) {
        QByteArray bytearray;
        bytearray = lengthPrefix+str.toUtf8();
        //bytearray.append("\r\n");
        clientSocket->write(bytearray);
    }
}
void Widget:: after_search(QString searchId)
{
    QString newPort;
    QMessageBox msgBox;
    msgBox.setText("NOTICE");
    msgBox.setInformativeText("Would you like to add this ID as a friend?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    int ret = msgBox.exec();
    chatWidget = new ChatWidget();
    switch (ret) {
      case QMessageBox::Yes:


        if(joinChatList.find(searchId)==joinChatList.end())
        {
            newPort = myInfo->getMyId()+":"+searchId;
            myInfo->addNewPort(searchId,newPort);
            chatList->addchatroom(searchId);
            joinChatList.insert(searchId,chatWidget);
            chatWidget->setWindowTitle(searchId);
            chatWidget->setChatroomName(searchId);
            connect(joinChatList[searchId],SIGNAL(signal_newMsg(QString)),this,SLOT(sendData(QString)));

            QJsonObject json;
                json["msgtype"] = 5;
                json["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODate);
                json["msgport"] = "newFriend for add";  // 추가 필드 예시
                json["sendcli"] = myInfo->getMyId(); // 읽음 여부 추가
                json["msgcontext"] = searchId;

            QString str = QString(QJsonDocument(json).toJson(QJsonDocument::Compact));
            QByteArray lengthPrefix = QByteArray::number(str.size()).rightJustified(4, '0');
            if(str.length()) {
                QByteArray bytearray;
                bytearray = lengthPrefix+str.toUtf8();
                //bytearray.append("\r\n");
                clientSocket->write(bytearray);
            }

        }
        else
        {
            QMessageBox connectError;
            connectError.setGeometry(
                QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    connectError.size(),
                    qApp->desktop()->availableGeometry())
                );
            QMessageBox::StandardButtons buttonCheck = QMessageBox::Ok;
            if(buttonCheck == connectError.warning(this,"[NOTICE] alread exist","already exist friend",QMessageBox::Ok))
            {
               qDebug()<<"Error : Fail Create Account";
               delete chatWidget;
            }
        }

        //chatWidget->show();

            break;
      case QMessageBox::No:
          // Don't Save was clicked
          break;
    default:
        break;
    }
}
void Widget::slot_newFriend(QString newFriend)
{
    ChatWidget* new_chatWidget = new ChatWidget();
    if(joinChatList.find(newFriend)==joinChatList.end())
    {
        QString newPort = myInfo->getMyId()+":"+newFriend;
        myInfo->addNewPort(newFriend,newPort);
        chatList->addchatroom(newFriend);
        joinChatList.insert(newFriend,new_chatWidget);

        QJsonObject json;
            json["msgtype"] = 5;
            json["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODate);
            json["msgport"] = "newFriend for add";  // 추가 필드 예시
            json["sendcli"] = myInfo->getMyId(); // 읽음 여부 추가
            json["msgcontext"] = newFriend;

        QString str = QString(QJsonDocument(json).toJson(QJsonDocument::Compact));
        QByteArray lengthPrefix = QByteArray::number(str.size()).rightJustified(4, '0');
        if(str.length()) {
            QByteArray bytearray;
            bytearray = lengthPrefix+str.toUtf8();
            //bytearray.append("\r\n");
            clientSocket->write(bytearray);
        }

        new_chatWidget->setWindowTitle(newFriend);
        new_chatWidget->setChatroomName(newFriend);
        connect(joinChatList[newFriend],SIGNAL(signal_newMsg(QString)),this,SLOT(sendData(QString)));
        joinChatList[newFriend]->show();
        myInfo->currentPort = newPort;
        joinChatList[newMessaage->getMsgSendCli()]->setText(newMessaage->getMsgSendCli(),"others:"+newMessaage->getMsgContext());
    }
    else
    {
         delete new_chatWidget;
        QMessageBox connectError;
        connectError.setGeometry(
            QStyle::alignedRect(
                Qt::LeftToRight,
                Qt::AlignCenter,
                connectError.size(),
                qApp->desktop()->availableGeometry())
            );
        QMessageBox::StandardButtons buttonCheck = QMessageBox::Ok;
        if(buttonCheck == connectError.warning(this,"[NOTICE] alread exist","already exist friend",QMessageBox::Ok))
        {
           qDebug()<<"Error : Fail Create Account";
        }

    }

}
void Widget::slot_makegroupchat()
{
   makeGroupChat->show();


}
