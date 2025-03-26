#ifndef FUNC2SERVER_H
#define FUNC2SERVER_H

#include <QByteArray>
#include <QString>
#include <QDebug>
#include <QTcpSocket> // для работы с сокетом

QByteArray parsing(const QString& request, int socket_id);

// Функции обработки запросов (заглушки)
QByteArray Auth(const QString& login, const QString& password);
QByteArray Registration(const QString& login, const QString& password, const QString& email);
QByteArray MyStats(int socket_id);
QByteArray AllStats();
QByteArray CheckAnswer(const QString& task, const QString& taskNumber, const QString& variant, const QString& answer,int socket_id);


#endif // FUNC2SERVER_H
