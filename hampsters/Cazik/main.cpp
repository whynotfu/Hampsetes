#include "managerform.h"

#include <QApplication>

#include <QSqlDatabase>

#include <QSqlQuery>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Инициализвания класса ManagerForm - в нем и находятся классы наших окон
    // При инициализации создадутся новые экземпляры классов окон (регистрации, меню, мини-игр...)
    ManagerForm w;

    return a.exec();
}
