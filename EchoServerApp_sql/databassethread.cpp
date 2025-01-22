#include "databassethread.h"
#include "clientitem.h"

#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <QMenu>
#include <QDebug>

DataBasseThread::DataBasseThread(QObject *obj)
{
        QSqlDatabase clientDB = QSqlDatabase::addDatabase("QSQLITE");
        clientDB.setDatabaseName("exdata.db");

        if (!clientDB.open()) {
            std::cerr << "Failed to open database: "
                      << clientDB.lastError().text().toStdString() << std::endl;
            std::exit(EXIT_FAILURE);
        }

        QSqlQuery query;
       if(!query.exec("CREATE TABLE IF NOT EXISTS client("
                   "m_clientNum INTEGER, "
                   "m_clientId VARCHAR(20), "
                   "m_clientPw VARCHAR(20) NOT NULL, "
                   "m_clientName VARCHAR(20) NOT NULL, "
                   "m_clientPhoneNum VARCHAR(20) NOT NULL, "
                   "m_clientAddress VARCHAR(20) NOT NULL);"))
       {
               std::cerr << "Error creating Users table: "
                         << query.lastError().text().toStdString() << std::endl;
        }
       // ChatRooms 테이블 생성
        if (!query.exec("CREATE TABLE IF NOT EXISTS ChatRooms ("
                        "room_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                        "room_name TEXT UNIQUE NOT NULL, "
                        "created_at DATETIME DEFAULT CURRENT_TIMESTAMP)")) {
            std::cerr << "Error creating ChatRooms table: "
                      << query.lastError().text().toStdString() << std::endl;
        }

        // UserChatRooms 테이블 생성
        if (!query.exec("CREATE TABLE IF NOT EXISTS UserChatRooms ("
                        "user_id INTEGER NOT NULL, "
                        "room_id INTEGER NOT NULL, "
                        "FOREIGN KEY(user_id) REFERENCES Users(id), "
                        "FOREIGN KEY(room_id) REFERENCES ChatRooms(room_id), "
                        "PRIMARY KEY(user_id, room_id))")) {
            std::cerr << "Error creating UserChatRooms table: "
                      << query.lastError().text().toStdString() << std::endl;
        }

        // Friends 테이블 생성
        if (!query.exec("CREATE TABLE IF NOT EXISTS Friends ("
                        "user_id INTEGER NOT NULL, "
                        "friend_id INTEGER NOT NULL, "
                        "FOREIGN KEY(user_id) REFERENCES Users(id), "
                        "FOREIGN KEY(friend_id) REFERENCES Users(id), "
                        "PRIMARY KEY(user_id, friend_id))")) {
            std::cerr << "Error creating Friends table: "
                      << query.lastError().text().toStdString() << std::endl;
        }

        // Messages 테이블 생성
        if (!query.exec("CREATE TABLE IF NOT EXISTS Messages ("
                        "message_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                        "room_id INTEGER NOT NULL, "
                        "sender_id INTEGER NOT NULL, "
                        "message TEXT NOT NULL, "
                        "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP, "
                        "FOREIGN KEY(room_id) REFERENCES ChatRooms(room_id), "
                        "FOREIGN KEY(sender_id) REFERENCES Users(id))")) {
            std::cerr << "Error creating Messages table: "
                      << query.lastError().text().toStdString() << std::endl;
        }


        clientModel = new QSqlTableModel();
        clientModel->setTable("client");
        clientModel->setEditStrategy(QSqlTableModel::OnFieldChange);
        clientModel->select();

        if (clientModel->rowCount() == 0) {
            std::cout << "Adding sample data..." << std::endl;
            insertData(clientModel, 0, "clientId", "password", "name", "phone", "address");
            if (!clientModel->submitAll()) {
                std::cerr << "Error adding sample data: "
                          << clientModel->lastError().text().toStdString() << std::endl;
            }
            clientModel->select();
        }

        if (clientList.isEmpty()) {
            for (int row = 0; row < clientModel->rowCount(); row++) {
                int num = clientModel->data(clientModel->index(row, 0)).toInt();
                QString id = clientModel->data(clientModel->index(row, 1)).toString();
                QString password = clientModel->data(clientModel->index(row, 2)).toString();
                QString name = clientModel->data(clientModel->index(row, 3)).toString();
                QString phoneNumber = clientModel->data(clientModel->index(row, 4)).toString();
                QString address = clientModel->data(clientModel->index(row, 5)).toString();

                ClientItem* c = new ClientItem(num, id, password, name, phoneNumber, address);
                clientList.insert(id, c);
            }
        }

        if (!clientList.isEmpty()) {
            for (const auto& v : clientList) {
                ClientItem* c = v;
                std::cout << c->getClientNum() << ", " << c->getClientId().toStdString() << ", "
                          << c->getClientPw().toStdString() << ", " << c->getClientName().toStdString() << ", "
                          << c->getClientPhoneNum().toStdString() << ", "
                          << c->getClientAddress().toStdString() << std::endl;
            }
        }

}
DataBasseThread::~DataBasseThread()
{
    clientModel->select( );
    std::cout <<"clientList.size : " << clientList.size() << std::endl;
    std::cout <<"clientModel->rowCount : " << clientModel->rowCount() << std::endl;
    int addrow = 0;
    int insR = clientModel->rowCount();
    while(clientModel->rowCount() < clientList.size())
    {
        int addrow = clientModel->rowCount();
        clientModel->insertRow(addrow++);
        //
        std::cout <<"insertRow : " << insR << std::endl;
        std::cout <<"clientList.size : " << clientList.size() << std::endl;
        std::cout <<"clientModel->rowCount : " << clientModel->rowCount() << std::endl;
    }
    std::cout <<"clientModel->rowCount : " << clientModel->rowCount() << std::endl;
    for (const auto& v : clientList)
    {
        ClientItem* c = v;
        std::cout <<"client id : " << c->getClientId().toStdString() << std::endl;
        int index = 0;
        for(index = 0; index<clientModel->rowCount(); index++)
        {
            if(c->getClientId() == clientModel->data(clientModel->index(index, 1)).toString())
            {
                std::cout <<"탈출 " << std::endl;
                break;
            }
        }
        if(index == clientModel->rowCount())
        {
            index = insR;
            insR++;
        }
        std::cout <<"index : " << index << std::endl;
        clientModel->setData(clientModel->index(index, 0), c->getClientNum()); // clientNum 대입
        cout << clientModel->data(clientModel->index(index, 0)).toString().toStdString()  << endl;
        cout << c->getClientNum() << endl;
        clientModel->setData(clientModel->index(index, 1), c->getClientId().toStdString().c_str()); // 수정된 ID 설정
        clientModel->setData(clientModel->index(index, 2), c->getClientPw().toStdString().c_str()); // 수정된 PW 설정
        clientModel->setData(clientModel->index(index, 3), c->getClientName().toStdString().c_str()); // 수정된 Name 설정
        clientModel->setData(clientModel->index(index, 4), c->getClientPhoneNum().toStdString().c_str()); // 수정된 PhoneNum 설정
        clientModel->setData(clientModel->index(index, 5), c->getClientAddress().toStdString().c_str()); // 수정된 Address 설정

        cout << index << endl;
    }
    cout << "도착"<<endl;
// */
    // 변경 사항을 데이터베이스에 저장
    if (!clientModel->submitAll()) {
        cout << "Error saving changes: " << clientModel->lastError().text().toStdString() << endl;
    }

}



void DataBasseThread::insertData(QSqlTableModel* model, int var1, const QString& var2, const QString& var3, const QString& var4, const QString& var5, const QString& var6) {
    int row = model->rowCount();
    model->insertRow(row);
    model->setData(model->index(row, 0), var1); // name column
    model->setData(model->index(row, 1), var2); // email column
    model->setData(model->index(row, 2), var3); // name column
    model->setData(model->index(row, 3), var4); // name column
    model->setData(model->index(row, 4), var5); // name column
    model->setData(model->index(row, 5), var6); // name column

    if (!model->submitAll()) {
        std::cout << "Error saving changes: " << model->lastError().text().toStdString() << std::endl;
    }
    model->select(); // Refresh the model to reflect changes

    std::cout << model->data(model->index(row, 0)).toString().toStdString().c_str() << std::endl; // name column
    std::cout << model->data(model->index(row, 1)).toString().toStdString().c_str() << std::endl; // name column
    std::cout << model->data(model->index(row, 2)).toString().toStdString().c_str() << std::endl; // name column
    std::cout << model->data(model->index(row, 3)).toString().toStdString().c_str() << std::endl; // name column
    std::cout << model->data(model->index(row, 4)).toString().toStdString().c_str() << std::endl; // name column
    std::cout << model->data(model->index(row, 5)).toString().toStdString().c_str() << std::endl; // name column

}

void DataBasseThread::printData(QSqlTableModel* model, int row, int column) {
    if (row < model->rowCount() && column < model->columnCount()) {
        QString data = model->data(model->index(row, column)).toString();
        std::cout << "Data at index (" << row << ", " << column << "): " << data.toStdString() << std::endl;
    } else {
        std::cout << "Index out of bounds." << std::endl;
    }
}

void DataBasseThread::inputClient()
{
    std::string id, pw, name, phoneNumber, address;

    std::cout << "id: "; std::cin >> id;
    std::cout << "pw: "; std::cin >> pw;
    std::cout << "name: "; std::cin >> name;
    std::cout << "phoneNumber: "; std::cin >> phoneNumber;
    std::cout << "address: "; std::cin.ignore(); std::getline(std::cin, address);

    int num = makeNum();
    ClientItem* c = new ClientItem(num, QString::fromStdString(id), QString::fromStdString(pw),
                                   QString::fromStdString(name), QString::fromStdString(phoneNumber),
                                   QString::fromStdString(address));
    addClient(c);
    cout << "here" << endl;
    //showClient();
}


ClientItem* DataBasseThread::search(QString id)
{
    if(clientList.find(id)!= clientList.end())
        return clientList[id];
    else
    {
        return nullptr;
    }
}
int DataBasseThread::contain(QString id)
{
    if(clientList.find(id)!= clientList.end())
        return 1;
    else
    {
        return 0;
    }
}

void DataBasseThread::deleteClient(QString key)
{
    ClientItem* c = clientList[key];

    for(int index = 0; index<clientModel->rowCount(); index++)
    {
        if(c->getClientNum() == clientModel->data(clientModel->index(index, 0)).toInt())
        {
            clientModel->removeRow(index);
            //clientModel->submitAll();
            //clientModel->select( );

            break;
        }
    }

    clientModel->submitAll();
    clientModel->select( );

    clientList.remove(key);
}


void DataBasseThread::addClient(ClientItem* c)
{
    clientList.insert(c->getClientId(), c);

    //객체 전달 확인 ok
    std::cout<< c->getClientId().toStdString().c_str() << std::endl;
    std::cout<< "addClient에서의 rowCount : " << clientModel->rowCount() << std::endl;

    int row = clientModel->rowCount();
    std::cout<< row << " : init clientModel : "<< clientModel->data(clientModel->index(row, 1)).toString().toStdString() << std::endl;
    clientModel->insertRow(row);
    clientModel->setData(clientModel->index(row, 0), c->getClientNum()); // clientNum 대입
 // /*
    //clientModel->setData(clientModel->index(row, 1), c->getClientId()); // 수정된 ID 설정
    clientModel->setData(clientModel->index(row, 1), c->getClientId()); // 수정된 ID 설정
    clientModel->setData(clientModel->index(row, 2), c->getClientPw()); // 수정된 PW 설정
    clientModel->setData(clientModel->index(row, 3), c->getClientName()); // 수정된 Name 설정
    clientModel->setData(clientModel->index(row, 4), c->getClientPhoneNum()); // 수정된 PhoneNum 설정
    clientModel->setData(clientModel->index(row, 5), c->getClientAddress()); // 수정된 Address 설정
 // */hj@hj-ZenBook-UX434DA-UM433DA:~/qt_ws/miniproject2/ClientApp$ ./ClientApp
   // "q,a,v,v,v"

 /*
    //const QString name = c->getClientId();

    //clientModel->setData(clientModel->index(row, 1), name); // 수정된 ID 설정
    clientModel->setData(clientModel->index(row, 1), c->getClientId().toStdString().c_str()); // 수정된 ID 설정
    clientModel->setData(clientModel->index(row, 2), c->getClientPw().toStdString().c_str()); // 수정된 PW 설정
    clientModel->setData(clientModel->index(row, 3), c->getClientName().toStdString().c_str()); // 수정된 Name 설정
    clientModel->setData(clientModel->index(row, 4), c->getClientPhoneNum().toStdString().c_str()); // 수정된 PhoneNum 설정
    clientModel->setData(clientModel->index(row, 5), c->getClientAddress().toStdString().c_str()); // 수정된 Address 설정
 */

    std::cout<< row << " : clientModel : "<< clientModel->data(clientModel->index(row, 1)).toString().toStdString() << std::endl;
    //clientModel->select( );

    if (!clientModel->submitAll()) {
        cout << "Error saving changes: " << clientModel->lastError().text().toStdString() << endl;
    }
    clientModel->select( );
    std::cout<< row << " : clientModel : "<< clientModel->data(clientModel->index(row, 1)).toString().toStdString() << std::endl;
    //std::cout<< row << " : clientModel : "<< clientModel->data(clientModel->index(row, 0)).toString().toStdString().c_str() << std::endl;
}


int DataBasseThread::makeNum( )
{
    if(clientList.size( ) == 0) {
        return 0;
    } else {
        auto id = clientList[clientList.lastKey()]->getClientNum();
        qDebug()<<"make Num : "<<id;
        return ++id;
    }
}

vector<QString> DataBasseThread::parseCSV(std::istream &file, char delimiter)
{
    std::string line;
    vector<QString> row;
    QString t = " \n\r\t";

    while (std::getline(file, line)) {
        QString qLine = QString::fromStdString(line); // std::string에서 QString으로 변환
        QStringList items = qLine.split(delimiter);
        for (QString& item : items) {
            item = item.trimmed(); // 양쪽 공백 제거
            row.push_back(item);
        }
    }
    return row;
}

// create 버튼 눌렀을 때 -> client 쪽에서 사용할 코드로 서버에선 x
// /*
// */

/* 데이터베이스 파일에서 clientModel로 데이터 복사하는 코드/ 클래스 객체 생성자에서 수행하도록 변경해서 사용x */
/*
static bool DataBasseThread::createConnection( )
{
    QSqlDatabase clientDB = QSqlDatabase::addDatabase("QSQLITE"); // WINDOW에선 QODBC를 사용할 수 있지만, 일관적으로 제공하는 SQLLITE를 사용
    clientDB.setDatabaseName("client_data.db"); // ":memory:" 으로 바꾸면 메모리에 저장하는데, 속도는 빠르지만, 파일에 저장은 안됨
    if (!clientDB.open( )) return false;

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS person(num INTEGER Primary Key, "
               "id VARCHAR(20) Primary Key, password VARCHAR(20) NOT NULL, name VARCHAR(20) NOT NULL, phoneNumber VARCHAR(20) NOT NULL, address VARCHAR(20) NOT NULL);");

    QSqlTableModel clientModel;
    clientModel->setTable("person");

    clientModel->select( );

    clientModel->setHeaderData(0, Qt::Horizontal, QObject::tr("ClientNum"));
    clientModel->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
    clientModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Password"));
    clientModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Name"));
    clientModel->setHeaderData(4, Qt::Horizontal, QObject::tr("PhoneNumber"));
    clientModel->setHeaderData(5, Qt::Horizontal, QObject::tr("Address"));

    return true;
}
*/

/* 고객 데이터베이스 출력하는 코드*/
void DataBasseThread::showClient()
{

    QTableView* tableview = new QTableView;
    tableview->setModel(clientModel);
    tableview->setWindowTitle(QObject::tr("Client DataBase"));
    tableview->show( ); //여기서 crashed

}

// 마우스 우클릭하면 뜨는 메뉴

//search 버튼 누르면

// 리스트에 있는 고객 정보를 클릭했을 때



void DataBasseThread::run()
{

}
void DataBasseThread::receive_clientInfo(QString newCliInfo)
{
    QString id, pw, name, number, address;
    qDebug()<<newCliInfo;
    QStringList splitInfo = newCliInfo.split(',');

    int num = makeNum( );
    id = splitInfo[5];
    pw =  splitInfo[6];
    name =  splitInfo[4];
    number =  splitInfo[7];
    address =  splitInfo[8];
    ClientItem* c = new ClientItem(num, id, pw, name, number, address);
    addClient(c);
    //clientList.insert(num, c);
    //showClient();receive_clientInfo
}
void DataBasseThread::process() {
    // allocate resources using new here
    qDebug("Hello World!");
    emit finished();
}
 void DataBasseThread::slot_search_loginInfo(QTcpSocket* sendSocket,QString id,QString pw)
 {
     if(search(id) == nullptr)
         emit result_login(sendSocket,"N");
     else
     {
         if(clientList[id]->getClientPw() == pw){
            emit result_login(sendSocket,"Y");
         }
         else
             emit result_login(sendSocket,"N");
     }
 }
void DataBasseThread:: get_friend_list(QString userId ,QTcpSocket* socket)
{
    QSqlQuery query;
    QList<QString> friends_list;
        query.prepare(R"(
            SELECT friend_id
            FROM Friends
            WHERE user_id = :user_id
        )");
        query.bindValue(":user_id", userId);

        if (!query.exec()) {
            qDebug("Error fetching friend list");
            QList<QString> error {"\0"};
            emit return_friends(error,socket);
        }
        while (query.next()) {
             friends_list.append(query.value(0).toString());
        }
       emit return_friends(friends_list,socket);
}
void DataBasseThread::slot_get_new_friend(QString userId,QString friendId)
{

    QSqlQuery query;
    query.prepare(R"(
        INSERT INTO Friends (user_id, friend_id)
        SELECT :user_id, :friend_id
        WHERE NOT EXISTS (
            SELECT 1 FROM Friends
            WHERE user_id = :user_id AND friend_id = :friend_id
        )
    )");
    query.bindValue(":user_id", userId);
    query.bindValue(":friend_id", friendId);

    if (!query.exec()) {
        qDebug("Error adding friend: ");
    }

    // 변경된 행 수 확인
    if (query.numRowsAffected() == 0) {
        qDebug()<<QString("Friend already exists: User %1 and Friend %2").arg (userId).arg(friendId);
    }

    qDebug()<<QString("Friend added successfully: User ") << QString(userId)
              << " added Friend " << QString(friendId);
}
