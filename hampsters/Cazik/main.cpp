/*!
 * \file main.cpp
 * \brief Точка входа в приложение.
 *
 * Этот файл содержит функцию main(), которая является точкой входа в приложение.
 * Здесь создается объект QApplication, инициализируется класс ManagerForm,
 * отвечающий за управление окнами приложения, и запускается основной цикл событий.
 */

#include "managerform.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Инициализация класса ManagerForm, в котором находятся классы окон (регистрация, меню, мини-игры и т.д.)
    ManagerForm w;

    return a.exec();
}
