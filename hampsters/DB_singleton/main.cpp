/**
 * @file main.cpp
 * @brief Тестовый файл для проверки работы синглтона базы данных
 * @author Команда разработчиков
 * @date 2025
 * @version 1.0
 * 
 * Содержит тестовый код для проверки функциональности DatabaseSingleton:
 * авторизации пользователей и получения статистики.
 */

#include <QCoreApplication>
#include <QDebug>
#include "databasesingleton.h"

/**
 * @brief Главная функция тестового приложения
 * @param argc Количество аргументов командной строки
 * @param argv Массив аргументов командной строки
 * @return Код завершения приложения
 * 
 * Тестирует работу синглтона базы данных: авторизацию пользователя
 * и получение статистики всех пользователей.
 */
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug()<<"fdgfdgfdgfdgd";

    DatabaseSingleton* dbInstance = DatabaseSingleton::getInstance();

    QString login = "bobr";   // Replace with a valid login
    QString password = "123"; // Replace with a valid password
    QString authResult = dbInstance->auth(login, password);
    qDebug() << "Authentication result:" << authResult;

    QList<QString> allStatsResult = dbInstance->AllStats(0);

    if (allStatsResult.size() == 1) {
        qDebug() << "AllStats result:" << allStatsResult[0];
    } else if (allStatsResult.size() == 1 && allStatsResult[0] == "allstats-") {
        qDebug() << "No stats found: " << allStatsResult[0];
    }
    else {
        qDebug() << "AllStats result:";
        foreach (const QString& stats, allStatsResult) {
            qDebug() << stats;
        }
    }
    return a.exec();
}
