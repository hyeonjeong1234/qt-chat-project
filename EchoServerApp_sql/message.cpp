#include "message.h"

Message::Message()
{

}
Message::~Message()
{}
void Message::setMsgNum(QString num)
{
    this->m_msgNum = num;
}
QString Message::getMsgNum()
{
    return m_msgNum;
}
void Message::setMsgPort(QString port)
{
    this->m_msgPort = port;
}
void Message::setMsgType(int type)
{
    this->m_msgType = type;
}
void Message::setMsgSendCLi(QString sendCli)
{
    this->m_msgSendCli = sendCli;
}
void Message::setMsgContext(QString context)
{
    this->m_msgContext = context;
}
QString Message::getMsgPort()
{
    return m_msgPort;
}
int Message::getMsgType()
{
    return m_msgType;
}
QString Message::getMsgSendCli()
{
    return m_msgSendCli;
}
QString Message::getMsgContext()
{
    return m_msgContext;
}
