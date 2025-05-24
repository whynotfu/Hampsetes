#include "clientapi.h"
#include "client_functions.h"

ClientApi * ClientApi::p_instance = nullptr;
SingletonDestroyer ClientApi::destroyer;

SingletonDestroyer::~SingletonDestroyer()
{
    delete p_instance;
}

void SingletonDestroyer::initialize(ClientApi * p)
{
    p_instance = p;
}

ClientApi::ClientApi(QObject *parent): QObject(parent)
{
    qDebug() << "1";
    mTcpSocket = new QTcpSocket(this);
    qDebug() << mTcpSocket->isOpen();
    connect(mTcpSocket, &QTcpSocket::disconnected,
            this, &ClientApi::slotServerDisconnection);
    qDebug() << "2";
    mTcpSocket->connectToHost("127.0.0.1",33333);
    qDebug() << "3";
}

ClientApi::~ClientApi()
{
    this->mTcpSocket->close();
}


ClientApi* ClientApi::getInstance(){
    if(!p_instance){
        p_instance = new ClientApi();
        destroyer.initialize(p_instance);
    }
    return p_instance;
}

void ClientApi::slotServerDisconnection()
{
    mTcpSocket->close();
}

QByteArray ClientApi::query_to_server(QString msg)
{
    if(not mTcpSocket->isOpen()){
        mTcpSocket->connectToHost("127.0.0.1",33333);
        if(!mTcpSocket->waitForConnected(3000)){
            return QByteArray("Connection error");
        }
    }
    mTcpSocket->write(msg.toUtf8());
    mTcpSocket->waitForReadyRead();
    QByteArray array;
    while(mTcpSocket->bytesAvailable()>0)
    {
        array.append(mTcpSocket->readAll());
    }
    qDebug()<<array;
    return array;
}

QString ClientApi::auth(QString login ,QString password)
{
    QString get = this->query_to_server("auth " + login + " " + password);

    if (get.split(" ")[0] == "auth+"){
        ids = 0;
        robuks = (get.split(" ")[3]).toInt();
        currentRole = get.split(" ")[2];
        TotalBets = (get.split(" ")[4]).toInt();
        TotalWins = (get.split(" ")[5]).toInt();
        currentUsername = get.split(" ")[1];
        if (currentRole == "admin"){
            ids = get.split(" ")[6];
        }
        return "auth+";
    }
    return "auth-";
}


QString ClientApi::reg(QString login, QString password, QString check_password)
{
    // Проверяем, что поля не пустые
    if (login.isEmpty() || password.isEmpty() || check_password.isEmpty()) {
        return "";
    }

    // Проверяем совпадение паролей
    if (password != check_password) {
        return "";
    }

    QString get = this->query_to_server("reg " + login + " " + password);
    return get;


}

QString ClientApi::toServer(int balance, int TotBets, int TotWin){
    QString get = this->query_to_server("account " + QString::number(balance)
                               + " " + QString::number(TotBets)
                               + " " + QString::number(TotWin));
    return get;
}

QString ClientApi::adminTo(QString login, int balance, int TotBets, int TotWin){
    QString get = this->query_to_server("admin_tool " + login + " " + QString::number(balance)
                                        + " " + QString::number(TotBets)
                                        + " " + QString::number(TotWin));
    return get;
}

QString ClientApi::one_stat(QString id){
    QString get = this->query_to_server("admin_tool " + id);
    return get;
}
