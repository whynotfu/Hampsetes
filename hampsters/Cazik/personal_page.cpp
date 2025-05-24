/**
 * @file personal_page.cpp
 * @brief Реализация персональной страницы пользователя
 * @author Команда разработчиков
 * @date 2025
 * @version 1.0
 * 
 * Содержит реализацию класса personal_page для отображения
 * статистики пользователя и управления личным кабинетом.
 */

#include "personal_page.h"
#include "ui_personal_page.h"
#include "client_functions.h" // Подключаем глобальные данные

#include <QLabel>
#include <QDebug>

personal_page::personal_page(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::personal_page)
{
    ui->setupUi(this);

    // Настройка окна
    this->setWindowIcon(QIcon(path() + "Images/icon.png"));
    this->setWindowTitle("Personal Page");
    this->setFixedSize(430, 330);

    // Загрузка фона
    QPixmap MainFon1(path() + "Images/personal_page_back.png");
    ui->MainFon->setPixmap(MainFon1);

    // Установка стиля для QLabel (белый текст)
    ui->labelLogin->setStyleSheet("color: white;");
    ui->labelRole->setStyleSheet("color: white;");
    ui->labelBalance->setStyleSheet("color: white;");
    ui->labelTotalBets->setStyleSheet("color: white;");
    ui->labelTotalWins->setStyleSheet("color: white;");
    ui->labelLastLogin->setStyleSheet("color: white;");
    ui->labelperson->setStyleSheet("color: white;");

    // Отображение статистики текущего пользователя (логин "bobr")
    displayUserStatistics("bobr");
}

personal_page::~personal_page()
{
    delete ui;
}

void personal_page::displayUserStatistics(const QString& currentUsername)
{
    // Найдем текущего пользователя в списке users
    int userIndex = -1;
    for (int i = 0; i < users.size(); ++i) {
        if (users[i].login == currentUsername) {
            userIndex = i;
            break;
        }
    }

    if (userIndex == -1) {
        qDebug() << "User not found!";
        return;
    }

    const User& currentUser = users[userIndex];

    // Установим данные в QLabel
    ui->labelperson->setText("Статистика пользователя " + currentUser.login);

    ui->labelLogin->setText(currentUser.login);
    ui->labelRole->setText(currentUser.role);
    ui->labelBalance->setText(QString::number(currentUser.balance));
    ui->labelTotalBets->setText(QString::number(currentUser.total_bets));
    ui->labelTotalWins->setText(QString::number(currentUser.total_wins));
    ui->labelLastLogin->setText(currentUser.last_login.toString("yyyy-MM-dd hh:mm:ss"));
}

void personal_page::slot_show(){
    this->show();
}
