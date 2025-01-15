#include "clientitem.h"

#include <QLabel>
#include <iostream>

using namespace std;

ClientItem::ClientItem(int num, QString id, QString pw, QString name, QString phoneNumber, QString address)
    :m_clientNum(num), m_clientId(id), m_clientPw(pw), m_clientName(name), m_clientPhoneNum(phoneNumber), m_clientAddress(address)
{
    cout << "생성자 호출" << endl;

    labelId = new QLabel(id, this);
    labelId->setGeometry(40, 0, 60, 18);

    labelPw = new QLabel(pw, this);
    labelPw->setGeometry(100, 0, 60, 18);

    labelName = new QLabel(name, this);
    labelName->setGeometry(160, 0, 60, 18);

    labelNumber = new QLabel(phoneNumber, this);
    labelNumber->setGeometry(220, 0, 60, 18);

    labelAddress = new QLabel(address, this);
    labelAddress->setGeometry(280, 0, 60, 18);
}

ClientItem::~ClientItem()
{
    if(labelId != nullptr)
        delete labelId;
    if(labelPw != nullptr)
        delete labelPw;
    if(labelName != nullptr)
        delete labelName;
    if(labelNumber != nullptr)
        delete labelNumber;
    if(labelAddress != nullptr)
        delete labelAddress;
}

QString ClientItem::getClientId() const
{
    return m_clientId;
}

void ClientItem::setClientId(QString& id)
{
    m_clientId = id;
    if(labelId != nullptr)
        labelId->setText(id);
}

QString ClientItem::getClientPw() const
{
    return m_clientPw;
}

void ClientItem::setClientPw(QString& pw)
{
    m_clientPw = pw;
    if(labelPw != nullptr)
        labelPw->setText(pw);
}

QString ClientItem::getClientName() const
{
    return m_clientName;
}

void ClientItem::setClientName(QString& name)
{
    m_clientName = name;
    if(labelName != nullptr)
        labelName->setText(name);
}

QString ClientItem::getClientPhoneNum() const
{
    return m_clientPhoneNum;
}

void ClientItem::setClientPhoneNum(QString& phoneNumber)
{
    m_clientPhoneNum = phoneNumber;
    if(labelNumber != nullptr)
        labelNumber->setText(phoneNumber);
}

QString ClientItem::getClientAddress() const
{
    return m_clientAddress;
}

void ClientItem::setClientAddress(QString& address)
{
    m_clientAddress = address;
    if(labelAddress != nullptr)
        labelAddress->setText(address);
}


// 추후에 getClientNum()로 이름변경
int ClientItem::getClientNum() const
{
    return m_clientNum;
}

// Define copy assignment operator.
bool ClientItem::operator==(const ClientItem &other) const {
    return (this->m_clientId == other.m_clientId);
}
