#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include <QString>
#include "func2server.h"

MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
    // Закрытие всех соединений
    for (QTcpSocket* socket : mClientSockets) {
        socket->close();
    }
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent)
{
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);

    if (!mTcpServer->listen(QHostAddress::Any, 33333)) {
        qDebug() << "server is not started";
    } else {
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection()
{
    mTcpSocket = mTcpServer->nextPendingConnection();
    mClientSockets.append(mTcpSocket);  // Добавляем новый сокет в список клиентов
    mTcpSocket->write("Hello, World!!! I am echo server!\r\n");

    connect(mTcpSocket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
    connect(mTcpSocket, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
}

void MyTcpServer::slotServerRead()
{
    QString res = "";
    while (mTcpSocket->bytesAvailable() > 0)
    {
        QByteArray array = mTcpSocket->readAll();
        qDebug() << array << "\n";

        QString receivedData = QString::fromUtf8(array);
        if (receivedData.endsWith("\r\n")) {
            receivedData.chop(2);
        }

        res.append(receivedData);
    }

    QByteArray response = parsing(res, mTcpSocket->socketDescriptor());
    mTcpSocket->write(response);
}

void MyTcpServer::slotClientDisconnected()
{
    mClientSockets.removeAll(mTcpSocket);  // Удаляем клиентский сокет из списка
    mTcpSocket->deleteLater();
}
