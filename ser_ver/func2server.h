#ifndef FUNC2SERVER_H
#define FUNC2SERVER_H

#include <QByteArray>
#include <QString>
#include <QDebug>
#include <QTcpSocket> // для работы с сокетом

QByteArray parsing(const QString& request);

// Функции обработки запросов (заглушки)
QByteArray Auth(const QString& login, const QString& password);
QByteArray Registration(const QString& login, const QString& password, const QString& email);
QByteArray MyStats();
QByteArray AllStats();


#endif // FUNC2SERVER_H
