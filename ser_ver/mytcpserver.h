#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();

private slots:
    void slotNewConnection();

private:
    QTcpServer* mTcpServer;
    QList<QTcpSocket*> mClientSockets;
    QByteArray parsing(const QString& data, qintptr descriptor);  // Заглушка
};

#endif // MYTCPSERVER_H
