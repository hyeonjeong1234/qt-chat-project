#ifndef MESSAGE_H
#define MESSAGE_H

#include<QString>

class Message
{
public:
    Message();
    ~Message();
    void setMsgNum(QString num);
    QString getMsgNum();
    void setMsgPort(QString port);
    void setMsgType(int type);
    void setMsgSendCLi(QString sendCli);
    void setMsgContext(QString context);
    void setMsgRevCli(QString revCli);
    QString getMsgPort();
    int getMsgType();
    QString getMsgSendCli();
    QString getMsgContext();
    QString getMsgRevCli();
private:
    int m_msgType;
    QString m_msgNum;//메시지 유형? 0=>회원정보(회원가입시), 1=>채팅메시지 이런식?
    QString m_msgPort;
    QString m_msgSendCli;
    QString m_msgContext;
    QString m_msgRevCli;
};

#endif // MESSAGE_H
//없는 거  공백으로 콤마만 찍어서 개수 맞춰주기 보내야함 아님 헷갌헷갈기
