#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
public slots:
    void slotNewConnection();
    void slotClientDisconnected();
    void slotServerRead();
private:
    QTcpServer * mTcpServer;
   // QTcpSocket * mTcpSocket;
    QVector <QTcpSocket*> Sockets;
    //int server_status;
};
#endif // MYTCPSERVER_H







