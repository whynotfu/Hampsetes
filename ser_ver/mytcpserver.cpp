#include "mytcpserver.h"
#include <QDebug>

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

MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
    for (QTcpSocket* socket : mClientSockets) {
        socket->close();
        socket->deleteLater();
    }
}

void MyTcpServer::slotNewConnection()
{
    QTcpSocket* clientSocket = mTcpServer->nextPendingConnection();
    mClientSockets.append(clientSocket);
    clientSocket->write("Hello, World!!! I am echo server!\r\n");

    connect(clientSocket, &QTcpSocket::readyRead, this, [this, clientSocket]() {
        QString res;
        while (clientSocket->bytesAvailable() > 0) {
            QByteArray array = clientSocket->readAll();
            qDebug() << array;

            QString receivedData = QString::fromUtf8(array);
            if (receivedData.endsWith("\r\n")) {
                receivedData.chop(2);
            }

            res.append(receivedData);
        }

        QByteArray response = parsing(res, clientSocket->socketDescriptor());
        clientSocket->write(response);
    });

    connect(clientSocket, &QTcpSocket::disconnected, this, [this, clientSocket]() {
        mClientSockets.removeAll(clientSocket);
        clientSocket->deleteLater();
    });
}

// Заглушка функции парсинга
QByteArray MyTcpServer::parsing(const QString& data, qintptr descriptor)
{
    QString response = QString("Echo [%1]: %2\r\n").arg(descriptor).arg(data);
    return response.toUtf8();
}
