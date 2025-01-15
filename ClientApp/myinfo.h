#ifndef MYINFO_H
#define MYINFO_H

#include<QString>
#include<QList>
#include <QMap>
class MyInfo
{
public:
    MyInfo();
    ~MyInfo();
    void setMyId(QString newId);
    QString getMyId();
    void addNewPort(QString roomName,QString newPort);
    int getPortIndex(QString findPort);
    void readInfoFile();
    void appendFile();
    QString searchPort(QString find);
    QString currentPort;


private:
    QString m_myID;
    QList<QString> m_myPortList;//indexOf이런걸로 검색 해서 인덱스 얻기 가능
    QMap<QString,QString> m_chatlist;
};

#endif // MYINFO_H
