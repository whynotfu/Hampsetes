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
    ui->labelperson->setStyleSheet("color: white;");
}

personal_page::~personal_page()
{
    delete ui;
}

void personal_page::displayUserStatistics()
{
    // Установим данные в QLabel
    ui->labelperson->setText("Статистика пользователя " + currentUsername);

    ui->labelLogin->setText(currentUsername);
    ui->labelRole->setText(currentRole);
    ui->labelBalance->setText(QString::number(robuks));
    ui->labelTotalBets->setText(QString::number(TotalBets));
    ui->labelTotalWins->setText(QString::number(TotalWins));
}

void personal_page::slot_show(){
    displayUserStatistics();
    this->show();
}
