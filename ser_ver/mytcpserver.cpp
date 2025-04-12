#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include<QString>
#include "func2server.h"
MyTcpServer::~MyTcpServer()
{

    mTcpServer->close();
    //server_status=0;
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
}

void MyTcpServer::slotNewConnection(){
    QTcpSocket* mTcpSocket = mTcpServer->nextPendingConnection();
    connect(mTcpSocket, &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
    connect(mTcpSocket,&QTcpSocket::disconnected,this,&MyTcpServer::slotClientDisconnected);

    Sockets.push_back(mTcpSocket);
}

void MyTcpServer::slotServerRead(){
    QTcpSocket* senderSocket = qobject_cast<QTcpSocket*>(sender());
    QString res = "";
    while(senderSocket->bytesAvailable()>0)
    {
        QByteArray array = senderSocket->readAll();
        qDebug() << array << "\n";

        QString receivedData = QString::fromUtf8(array);
        if (receivedData.endsWith("\r\n")) {
            receivedData.chop(2);
        }

        if(array=="\x01")
        {
            senderSocket->write(parsing(res));
            res = "";
        }
        else
            res.append(receivedData);
    }
    senderSocket->write(parsing(res));
}

void MyTcpServer::slotClientDisconnected(){
    QTcpSocket* senderSocket = qobject_cast<QTcpSocket*>(sender());
    senderSocket->close();
}
