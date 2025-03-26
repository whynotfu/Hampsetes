#include <QCoreApplication>
#include <QDebug>
#include "databasesingleton.h"
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
