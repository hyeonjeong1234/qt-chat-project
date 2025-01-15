#include "myinfo.h"

MyInfo::MyInfo()
{
   //m_chatlist.insert("김철수","66666");
}
MyInfo::~MyInfo()
{

}

void MyInfo:: setMyId(QString newId)
{
    m_myID = newId;
}
QString MyInfo:: getMyId()
{
    return m_myID;
}
void MyInfo::addNewPort(QString roomName,QString newPort)
{
    m_chatlist.insert(roomName,newPort);
}
int MyInfo::getPortIndex(QString findPort)
{
    return m_myPortList.indexOf(findPort);//없으면 -1return
}
void MyInfo:: readInfoFile()
{

}
void MyInfo::appendFile()
{

}

QString MyInfo::searchPort(QString find)
{
    QMap<QString, QString>::iterator i = m_chatlist.find(find);
    if(i == m_chatlist.end())
    {
        return "-1";
    }
    else
    {
        return m_chatlist[find];
    }
}
