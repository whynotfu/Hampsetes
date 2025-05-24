#include "kosti.h"
#include "ui_kosti.h"
#include "client_functions.h"
#include <cstdlib>
#include <ctime>


Kosti::Kosti(QWidget *parent)
    : QDialog(parent),
    clientApi(ClientApi::getInstance()),
    ui(new Ui::Kosti)
{
    ui->setupUi(this);
    ui->count_robux->setText(QString::number(robuks));

    // Настройка окна
    this->setWindowIcon(QIcon(path() + "Images/icon.png"));
    this->setWindowTitle("Kosti");
    this->setFixedSize(800,600);

    // Инициализация изображений кубиков
    ui->label_dice1->setPixmap(QPixmap(path() + "Images/dice1.png"));
    ui->label_dice2->setPixmap(QPixmap(path() + "Images/dice1.png"));
    QPixmap MainFon(path() + "Images/MainFon.png");
    ui->MainFon->setPixmap(MainFon);

    this->size_of_stavka = 0;

    // Подключение сигналов кнопок
    connect(ui->pushButtonPlay, &QPushButton::clicked, this, &Kosti::on_pushButtonPlay_clicked);
    connect(ui->pushButton1000, &QPushButton::clicked, this, &Kosti::on_pushButton1000_clicked);
    connect(ui->pushButton500, &QPushButton::clicked, this, &Kosti::on_pushButton500_clicked);
    connect(ui->pushButton100, &QPushButton::clicked, this, &Kosti::on_pushButton100_clicked);
    connect(ui->BackButton, &QPushButton::clicked, this, &Kosti::on_BackButton_clicked);
}

void Kosti::slot_show(){
    ui->count_robux->setText(QString::number(robuks));
    this->show();
    // ui->count_robux->setText(QString::number(robuks));
}

Kosti::~Kosti()
{
    delete ui;
}

void Kosti::on_pushButtonPlay_clicked()
{
    if (size_of_stavka > 0 && robuks >= size_of_stavka) {
        robuks -= size_of_stavka;
        ui->count_robux->setText(QString::number(robuks));

        // Бросаем кубики
        rollDice();
    }
}

void Kosti::rollDice()
{
    // Генерация случайных чисел для двух кубиков
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;

    // Обновление изображений кубиков
    updateDiceImages(dice1, dice2);

    // Показываем результат игры
    showResult(dice1, dice2);
}

void Kosti::updateDiceImages(int dice1, int dice2)
{
    ui->label_dice1->setPixmap(QPixmap(path() + "Images/dice" + QString::number(dice1) + ".png"));
    ui->label_dice2->setPixmap(QPixmap(path() + "Images/dice" + QString::number(dice2) + ".png"));
}

void Kosti::showResult(int dice1, int dice2)
{

    if (dice1 > dice2) {
        ui->label_result->setText("Вы выиграли! + " + QString::number(size_of_stavka * 2) + " Робуксов");
        robuks += size_of_stavka * 2;
        TotalWins += size_of_stavka * 2;
        TotalBets += 1;
    } else {
        ui->label_result->setText("Вы проиграли! - " + QString::number(size_of_stavka) + " Робуксов");
    }
    ui->count_robux->setText(QString::number(robuks));
}

void Kosti::on_pushButton1000_clicked()
{
    ui->label_stavka->setText("Ставка: 1000");
    size_of_stavka = 1000;
}

void Kosti::on_pushButton500_clicked()
{
    ui->label_stavka->setText("Ставка: 500");
    size_of_stavka = 500;
}

void Kosti::on_pushButton100_clicked()
{
    ui->label_stavka->setText("Ставка: 100");
    size_of_stavka = 100;
}

void Kosti::on_BackButton_clicked()
{
    qDebug() << clientApi->toServer(robuks,TotalBets, TotalWins);
    emit to_main(ui->count_robux->text());
    this->close();
}
void Kosti::updateBalance()
{
    ui->count_robux->setText(QString::number(robuks));
}
