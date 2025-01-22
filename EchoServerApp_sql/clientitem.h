#ifndef CLIENTITEM_H
#define CLIENTITEM_H

#include <iostream>

using namespace std;

#include <QWidget>

class QLabel;

class ClientItem : public QWidget
{
    Q_OBJECT
public:
    explicit ClientItem(int num = -1, QString = "", QString = "", QString = "", QString = "", QString = "");
    ~ClientItem();

    QString getClientId() const;
    void setClientId(QString&);
    QString getClientPw() const;
    void setClientPw(QString&);
    QString getClientName() const;
    void setClientName(QString&);
    QString getClientPhoneNum() const;
    void setClientPhoneNum(QString&);
    QString getClientAddress() const;
    void setClientAddress(QString&);

    int getClientNum() const;
    bool operator==(const ClientItem &other) const;

private:
    int m_clientNum;
    QString m_clientId;
    QString m_clientPw;
    QString m_clientName;
    QString m_clientPhoneNum;
    QString m_clientAddress;
    QLabel* labelId;
    QLabel* labelPw;
    QLabel* labelName;
    QLabel* labelNumber;
    QLabel* labelAddress;
};

#endif // CLIENTITEM_H
