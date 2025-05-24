#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include<QString>
MyTcpServer::~MyTcpServer()
{
    delete []Socket_Login;
    mTcpServer->close();
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        //server_status=1;
        qDebug() << "server is started";
    }
    Socket_Login = new QMap<QTcpSocket*, QString>;
    DataBaseSingleton* database = DataBaseSingleton::getInstance();
    this->db = database;
    qDebug() << "DataBase address: " << this->db;
}

void MyTcpServer::slotNewConnection(){
    mTcpSocket = mTcpServer->nextPendingConnection();
    connect(mTcpSocket, &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
    connect(mTcpSocket,&QTcpSocket::disconnected,this,&MyTcpServer::slotClientDisconnected);

    Sockets.push_back(mTcpSocket);
}

void MyTcpServer::slotServerRead(){

    QTcpSocket* senderSocket = qobject_cast<QTcpSocket*>(sender());
    if (!senderSocket) return; // проверка, dynamic cast сработал или нет
    QString res = "";
    while(senderSocket->bytesAvailable()>0)
    {
        QByteArray array =senderSocket->readAll();
        if(array=="\x01")
        {
            res = "";
        }
        else
            res.append(array);
    }
    senderSocket->write(Parsing(res.toUtf8()).toUtf8());
}
void MyTcpServer::slotClientDisconnected(){
    QTcpSocket* disconnectedSocket = qobject_cast<QTcpSocket*>(sender());
    if (!disconnectedSocket){
        Sockets.remove(Sockets.indexOf(disconnectedSocket));
        return;
    }
    Sockets.remove(Sockets.indexOf(disconnectedSocket));
    disconnectedSocket->close();
}

QString MyTcpServer::Parsing(QString inputs)
{
    QString command_string = inputs;
    //строка inputs это строка с параметрами, по которым сервер определяет что отправить клиенту обратно
    //константы параметров для команд
    const int auth_params_const = 3;
    const int reg_params_const = 3;
    //Для среза "\r\n";
    if(inputs.indexOf("\r\n") > 0){
    int r_index = 0;
    for(int i = 0; i < inputs.length(); i++){if(inputs[i] == '\r'){r_index = i;}}
    command_string = inputs.replace(r_index, 2, "");
    }
    QTcpSocket* sendSocket = qobject_cast<QTcpSocket*>(sender());
    qDebug() << Sockets.indexOf(sendSocket) <<  ":" <<inputs;
    if(command_string.count(" ") != 0) // проверка, что в строке вообще есть пробелы
    {
        QString command = command_string.split(" ")[0]; // команда
        int count_of_params = command_string.split(" ").length(); // количество параметров
        if(command == "auth" && count_of_params == auth_params_const)
        {
        // auth <login> <password>
            QString login = command_string.split(" ")[1];
            Socket_Login->insert(sendSocket, login);
            QString password = command_string.split(" ")[2];
            return db->auth(login, password);
        }
        else if(command == "reg" && count_of_params == reg_params_const)
        {
        // reg <login> <password>
            QString login = command_string.split(" ")[1];
            QString password = command_string.split(" ")[2];
            return db->reg(login, password);
        }
        else if(command == "account" && count_of_params == 4)
        {
            QString login = Socket_Login->value(sendSocket);
            QString balance = command_string.split(" ")[1];
            QString totalBets = command_string.split(" ")[2];
            QString totalWins = command_string.split(" ")[3];
            return this->db->toAccount(login, balance, totalBets, totalWins);
        }//account <balance> <totalBets> <totalWins>
        else if(command == "admin_tool")
        {
            if(count_of_params == 2)//admin_tool <id> получение для админа всех полей пользователя
            {
                QString id = command_string.split(" ")[1];
                return this->db->UserData(id);
            }
            else if(count_of_params == 5)//admin_tool login balance totalbets totalwins
            {
                QString login = command_string.split(" ")[1];
                QString balance = command_string.split(" ")[2];
                QString totalBets = command_string.split(" ")[3];
                QString totalWins = command_string.split(" ")[4];
                return this->db->toAccount(login, balance, totalBets, totalWins);
            }
        }
        else{
            return "invalid command";
        }
    }
    else
    {
        return "invalid request";
    }
    return "Critical Error";
}
