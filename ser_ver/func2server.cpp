/**
 * @file func2server.cpp
 * @brief Реализация функций обработки запросов сервера
 * @author Команда разработчиков
 * @date 2025
 * @version 1.0
 * 
 * Содержит реализацию функций для парсинга и обработки
 * различных типов запросов от клиентов казино.
 */

#include "func2server.h"


QByteArray parsing(const QString& request) {
   // Q_UNUSED(socket)

    qDebug() << "Parsing request: " << request;

    QStringList parts = request.split(" ", Qt::SkipEmptyParts);
    if (parts.isEmpty()) {
        return "Error: Empty command.\r\n";
    }

    QString command = parts.at(0).toLower();

    if (command == "auth" && parts.size() == 3) {
        return Auth(parts.at(1), parts.at(2));
    } else if (command == "reg" && parts.size() == 4) {
        return Registration(parts.at(1), parts.at(2), parts.at(3));
    } else if (command == "mystats" && parts.size() == 1) {
        return MyStats();
    } else if (command == "allstats" && parts.size() == 1) {
        return AllStats();
    }
      else if (command.startsWith("hello")) {
        return "Nice to meet you! Available commands: auth, reg, mystats, allstats, check\r\n";
    } else {
        return "Error: Unknown command or invalid format. Available commands: auth, reg, mystats, allstats, check\r\n";
    }
}

QByteArray Auth(const QString& login, const QString& password) {
    qDebug() << "Authenticating user: " << login;
    return ("auth+" + login).toUtf8() + "\r\n";
}

QByteArray Registration(const QString& login, const QString& password, const QString& email) {
    qDebug() << "Registering user: " << login << " with email: " << email;
    return ("reg+" + login).toUtf8() + "\r\n";
}

QByteArray MyStats() {
    qDebug() << "Returning my stats";
    return "mystats+Placeholder for my stats\r\n";
}

QByteArray AllStats() {
    qDebug() << "Returning all stats";
    return "allstats+Placeholder for all stats\r\n";
}

QByteArray CheckAnswer(const QString& task, const QString& taskNumber, const QString& variant, const QString& answer,int socket_id) {
    qDebug() << "Checking answer for task: " << task << ", number: " << taskNumber << ", variant: " << variant << ", answer: " << answer;
    return "check+Correct/Incorrect\r\n";
}
