#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QList>  // Для хранения списка клиентов

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();

public slots:
    void slotNewConnection();        // Обработчик нового подключения
    void slotClientDisconnected();   // Обработчик отключения клиента
    void slotServerRead();           // Обработчик чтения данных от клиента

private:
    QTcpServer *mTcpServer;          // Слушающий сервер
    QTcpSocket *mTcpSocket;          // Сокет для одного клиента
    QList<QTcpSocket*> mClientSockets; // Список для хранения всех клиентов

    void sendToAllClients(const QString &message); // Функция для отправки сообщений всем клиентам
};

#endif // MYTCPSERVER_H
