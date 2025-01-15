#include "clientmanagerform.h"
#include "ui_clientmanagerform.h"
#include "clientitem.h"

#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <QMenu>
#include <QDebug>



/*
ClientManagerForm::ClientManagerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientManagerForm)
{
    ui->setupUi(this);

    QAction* removeAction = new QAction("&Remove");
    connect(removeAction, SIGNAL(triggered()), SLOT(removeItem()));

    menu = new QMenu;
    menu->addAction(removeAction);
    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));

    ifstream file;
    file.open("clientlist.txt");
    if(!file.fail()) {
        while(!file.eof()) {
            vector<QString> row = parseCSV(file, ',');
            if(row.size()) {
                int num = atoi(row[0].toStdString().c_str());
                ClientItem* c = new ClientItem(num, row[1], row[2], row[3], row[4], row[5]);
                QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
                item->setText(row[0]);
                ui->listWidget->setItemWidget(item, c);
                clientList.insert(num, c);
            }
        }
    }
    file.close( );
}
*/
ClientManagerForm::ClientManagerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientManagerForm)
{
    ui->setupUi(this);

    QAction* removeAction = new QAction("&Remove");
    connect(removeAction, SIGNAL(triggered()), SLOT(removeItem()));
    int isData = 0;
    menu = new QMenu;
    menu->addAction(removeAction);
    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));
    std::cout << "managerform 생성자 호출" << std::endl;
    // 추가부분 시작
    QSqlDatabase clientDB = QSqlDatabase::addDatabase("QSQLITE"); // WINDOW에선 QODBC를 사용할 수 있지만, 일관적으로 제공하는 SQLLITE를 사용
    //clientDB.setDatabaseName("data.db"); // ":memory:" 으로 바꾸면 메모리에 저장하는데, 속도는 빠르지만, 파일에 저장은 안됨
    clientDB.setDatabaseName("exdata.db"); // ":memory:" 으로 바꾸면 메모리에 저장하는데, 속도는 빠르지만, 파일에 저장은 안됨

    if (!clientDB.open( )) cout << "fail" << endl;

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS client(m_clientNum INTEGER, m_clientId VARCHAR(20), m_clientPw VARCHAR(20) NOT NULL, m_clientName VARCHAR(20) NOT NULL, m_clientPhoneNum VARCHAR(20) NOT NULL, m_clientAddress VARCHAR(20) NOT NULL);");
    //query.exec("CREATE TABLE IF NOT EXISTS client(num INTEGER, id VARCHAR(20) Primary Key, password VARCHAR(20) NOT NULL, name VARCHAR(20) NOT NULL, phoneNumber VARCHAR(20) NOT NULL, address VARCHAR(20) NOT NULL);");

    clientModel = new QSqlTableModel();

    //tableview = new QTableView(this);
    clientModel->setTable("client");
    clientModel->setEditStrategy(QSqlTableModel::OnFieldChange);
    clientModel->select();

    clientModel->setHeaderData(0, Qt::Horizontal, QObject::tr("m_clientNum"));
    clientModel->setHeaderData(1, Qt::Horizontal, QObject::tr("m_clientId"));
    clientModel->setHeaderData(2, Qt::Horizontal, QObject::tr("m_clientPw"));
    clientModel->setHeaderData(3, Qt::Horizontal, QObject::tr("m_clientName"));
    clientModel->setHeaderData(4, Qt::Horizontal, QObject::tr("m_clientPhoneNum"));
    clientModel->setHeaderData(5, Qt::Horizontal, QObject::tr("m_clientAddress"));

//    /*
    if (clientModel->rowCount() == 2) {
        // 데이터가 없으면 샘플 데이터 추가
        std::cout << "데이터 샘플 추가" << std::endl;
        insertData(clientModel, 0, "clientId", "password", "name", "phone", "address");
        if (!clientModel->submitAll()) {
            cout << "Error adding sample data : " << clientModel->lastError().text().toStdString() << endl;
        }
        clientModel->select();
    }
//    */
    //clientModel->select( );
    std::cout << "init rowCount : " << clientModel->rowCount() << std::endl;
    for (int row = 0; row < clientModel->rowCount(); row++) {
        int num = clientModel->data(clientModel->index(row, 0)).toInt();
        QString id = clientModel->data(clientModel->index(row, 1)).toString(); // ID
        QString password = clientModel->data(clientModel->index(row, 2)).toString(); // Password
        QString name = clientModel->data(clientModel->index(row, 3)).toString(); // Name
        QString phoneNumber = clientModel->data(clientModel->index(row, 4)).toString(); // Phone Number
        QString address = clientModel->data(clientModel->index(row, 5)).toString(); // Address
        std::cout << " row value : " << row << std::endl;
        //std::cout << "init rowCount : " << clientModel->rowCount() << std::endl;
        ClientItem* c = new ClientItem(num, id, password, name, phoneNumber, address);
        clientList.insert(num, c);
        std::cout << "address : /" << address.toStdString() << "id : /" << id.toStdString() << "password : /" << password.toStdString() << "/"  << std::endl;
        std::cout << "c.address : /" << c->getClientAddress().toStdString() << "c.id : /" << c->getClientId().toStdString() << "c.password : /" << c->getClientPw().toStdString() << "/"  << std::endl;
        isData = 1;
    }
    if (!clientModel->submitAll()) {
        cout << "Error first saving changes: " << clientModel->lastError().text().toStdString() << endl;
    }
    clientModel->select();
    if(isData != 0)
    {
        for (const auto& v : clientList) {
            ClientItem* c = v;
            std::cout << c->getClientNum() << ", ";
            std::cout << c->getClientId().toStdString() << ", " << c->getClientPw().toStdString() << ", ";
            std::cout << c->getClientName().toStdString() << ", " << c->getClientPhoneNum().toStdString() << ", ";
            std::cout << c->getClientAddress().toStdString() << std::endl;
        }
    }
    showClient();


    //추가부분 끝

    //csv 파일에서 데이터를 읽어오는 코드 -> 사용x
    /*
    if(!file.fail()) {
        while(!file.eof()) {
            vector<QString> row = parseCSV(file, ',');
            if(row.size()) {
                int num = atoi(row[0].toStdString().c_str());
                ClientItem* c = new ClientItem(num, row[1], row[2], row[3], row[4], row[5]);
                QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
                item->setText(row[0]);
                ui->listWidget->setItemWidget(item, c);
                clientList.insert(num, c);
            }
        }
    }
    file.close( );
    */
}




ClientManagerForm::~ClientManagerForm()
{
    delete ui;
// /*
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

// 데이터를 csv 파일에 저장하는 코드 -> 사용x
/*
ClientManagerForm::~ClientManagerForm()
{
    delete ui;

    ofstream file;
    file.open("clientlist.txt");
    if(!file.fail()) {
        for (const auto& v : clientList) {
            ClientItem* c = v;
            file << c->getClientNum() << ", ";
            file << c->getClientId().toStdString().c_str() << ", " << c->getClientPw().toStdString().c_str() << ", ";
            file << c->getClientName().toStdString().c_str() << ", " << c->getClientPhoneNum().toStdString().c_str() << ", ";
            file << c->getClientAddress().toStdString().c_str() << endl;
        }
    }
    file.close( );
}
*/

void ClientManagerForm::insertData(QSqlTableModel* model, int var1, const QString& var2, const QString& var3, const QString& var4, const QString& var5, const QString& var6) {
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

void ClientManagerForm::printData(QSqlTableModel* model, int row, int column) {
    if (row < model->rowCount() && column < model->columnCount()) {
        QString data = model->data(model->index(row, column)).toString();
        std::cout << "Data at index (" << row << ", " << column << "): " << data.toStdString() << std::endl;
    } else {
        std::cout << "Index out of bounds." << std::endl;
    }
}

void ClientManagerForm::inputClient()
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


ClientItem* ClientManagerForm::search(int num)
{
    return clientList[num];
}

void ClientManagerForm::deleteClient(int key)
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


void ClientManagerForm::addClient(ClientItem* c)
{
    clientList.insert(c->getClientNum(), c);

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
 // */
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


int ClientManagerForm::makeNum( )
{
    if(clientList.size( ) == 0) {
        return 0;
    } else {
        auto id = clientList.lastKey();
        return ++id;
    }
}

vector<QString> ClientManagerForm::parseCSV(std::istream &file, char delimiter)
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
void ClientManagerForm::on_pushButton_clicked()//tcp 통신한거 받는 부분으로 바꾸기??
{
    qDebug("on_pushButton_clicked");
    QString id, pw, name, number, address;
    int num = makeNum( );
    id = ui->lineEditID->text().toUtf8();
    pw = ui->lineEditPW->text().toUtf8();
    name = ui->lineEditName->text().toUtf8();
    number = ui->lineEditPhoneNumber->text().toUtf8();
    address = ui->lineEditAddress->text().toUtf8();
    ClientItem* c = new ClientItem(num, id, pw, name, number, address);
    addClient(c);
    //clientList.insert(num, c);
    QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
    item->setText(QString::number(num));
    ui->listWidget->setItemWidget(item, c);
    //showClient();
    std::cout << "이게 실행1?" <<std::endl;
}
// */

void ClientManagerForm::removeItem()
{
    QListWidgetItem* item = ui->listWidget->currentItem();
    //clientList.remove(item->text().toInt());
    deleteClient(item->text().toInt());
    ui->listWidget->takeItem(ui->listWidget->currentRow());
    ui->listWidget->update();
}

/* 데이터베이스 파일에서 clientModel로 데이터 복사하는 코드/ 클래스 객체 생성자에서 수행하도록 변경해서 사용x */
/*
static bool ClientManagerForm::createConnection( )
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
void ClientManagerForm::showClient()
{

    QTableView* tableview = new QTableView;
    tableview->setModel(clientModel);
    tableview->setWindowTitle(QObject::tr("Client DataBase"));
    tableview->show( ); //여기서 crashed

}

// 마우스 우클릭하면 뜨는 메뉴
void ClientManagerForm::showContextMenu(const QPoint &pos)
{
    qDebug("ShowContextMenu");
    QPoint globalPos = ui->listWidget->mapToGlobal(pos);
    menu->exec(globalPos);
}

//search 버튼 누르면
void ClientManagerForm::on_pushButton_3_clicked()
{
    qDebug("on_pushButton_3_clicked");
    auto items = ui->listWidget->findItems(ui->lineEditSearch->text(), Qt::MatchCaseSensitive);

    ui->listWidgetSearch->clear();
    for (const auto& item : items) {
        ui->listWidgetSearch->addItem(item);
        QWidget *widget = ui->listWidget->itemWidget(item);
        QWidget* newWidget = new QWidget(this);

        QListWidgetItem* i = new QListWidgetItem(ui->listWidgetSearch);
        i->setText(item->text());

        int cnt = 0;
        int xPos[5] = {40, 100, 200, 300, 400};
        int widths[5] = {60, 100, 140, 180, 280};
        if(widget != nullptr)
            for (const auto& c : widget->children()) {
                QLabel* l = qobject_cast<QLabel*>(c);
                QLabel* label = new QLabel(l->text(), newWidget);
                label->setGeometry(xPos[cnt], 0, widths[cnt], 18);
                cnt++;
                qDebug() << l->text();
            }
        ui->listWidgetSearch->setItemWidget(i, newWidget);
    }
}

// 리스트에 있는 고객 정보를 클릭했을 때
void ClientManagerForm::on_listWidget_itemClicked(QListWidgetItem *item)
{
    qDebug("on_listWidget_itemClicked");
    QWidget *widget = ui->listWidget->itemWidget(item);
    ui->lineEditNum->setText(item->text());

    int cnt = 0;
    QList<QLineEdit*> leList;
    leList << ui->lineEditID;
    leList << ui->lineEditPW;
    leList << ui->lineEditName;
    leList << ui->lineEditPhoneNumber;
    leList << ui->lineEditAddress;

    if(widget != nullptr)
        for (const auto& c : widget->children()) {
            QLabel* l = qobject_cast<QLabel*>(c);
            leList.at(cnt++)->setText(l->text());
            //test 코드
            cout << "cnt : " << cnt << endl;
        }
}

void ClientManagerForm::on_pushButtonModify_clicked()
{
    qDebug("on_pushButtonModify_clicked");
    int key = ui->listWidget->currentItem()->text().toInt();
    ClientItem* c = search(key);
    QString id, pw, name, number, address;
    id = ui->lineEditID->text().toUtf8();
    pw = ui->lineEditPW->text().toUtf8();
    name = ui->lineEditName->text().toUtf8();
    number = ui->lineEditPhoneNumber->text().toUtf8();
    address = ui->lineEditAddress->text().toUtf8();
    c->setClientId(id);
    c->setClientPw(pw);
    c->setClientName(name);
    c->setClientPhoneNum(number);
    c->setClientAddress(address);
    clientList.insert(key, c);
}
