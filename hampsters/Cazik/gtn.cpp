/**
 * @file gtn.cpp
 * @brief Реализация игры "Угадай число" (Больше-Меньше)
 * @author Команда разработчиков
 * @date 2025
 * @version 1.0
 * 
 * Содержит реализацию класса Gtn - логической мини-игры,
 * где игрок угадывает случайное число, выбирая "больше" или "меньше".
 */

#include "gtn.h"
#include "ui_gtn.h"
#include "client_functions.h"

#include <cstdlib>
#include <ctime>

Gtn::Gtn(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Gtn)
{
    ui->setupUi(this);

    //настройки окна: иконка, название формы, фиксированный размер
    this->setWindowIcon(QIcon(path() + "Images/icon.png"));
    this->setWindowTitle("Guess the nubmer");
    this->setFixedSize(800,600);

    //картинка для фона
    QPixmap KlikerFon(path() + "Images/GamesFon.png");
    ui->Fonlabel->setPixmap(KlikerFon);

    //Картинка робуксов
    QPixmap RobuxLabel(path() + "Images/Robux.png");
    ui->label_robux->setPixmap(RobuxLabel);

    QPixmap Strelka(path() + "Images/Strelka.png");
    ui->StrelkaLabel->setPixmap(Strelka);
    ui->StrelkaLabel->setGeometry(-999,-999,31,31);

    QPixmap Strelka2(path() + "Images/Strelka2.png");
    ui->StrelkaLabel_2->setPixmap(Strelka2);
    ui->StrelkaLabel_2->setGeometry(-999,-999,31,31);

    this->block = 1;
    ui->play_button->setDisabled(1);
    srand(time(0));
    this->rstavka = -1;
    this->zstavka = -1;
}

Gtn::~Gtn()
{
    delete ui;
}

void Gtn::slot_show(){
    this->show();
    ui->count_robux->setText(QString::number(robuks));
}

void Gtn::on_new_number_clicked()
{
    this->now_num = this->new_number();
    this->num = this->new_number();

    if (this->now_num > 90){this->now_num = 90;}
    if (this->now_num < 10){this->now_num = 10;}

    ui->play_button->setDisabled(0);
    ui->label_number->setText(QString::number(this->now_num));
    ui->text->setText("Задано число. Оно больше "+QString::number(this->now_num)+" или нет?");
}

int Gtn::new_number(){
    this->block = 0;
    return std::rand() % 100 + 1;
}


void Gtn::on_button100_clicked()
{
    if (robuks >= 100){
    ui->StrelkaLabel->setGeometry(210,450,31,31);
    this->rstavka = 100;
    }
}


void Gtn::on_button500_clicked()
{
    if (robuks >= 500){
    ui->StrelkaLabel->setGeometry(310,450,31,31);
    this->rstavka = 500;
    }
}


void Gtn::on_button1000_clicked()
{
    if (robuks >= 1000){
    ui->StrelkaLabel->setGeometry(390,450,31,31);
    this->rstavka = 1000;
    }
}


void Gtn::on_greater_button_clicked()
{
    ui->StrelkaLabel_2->setGeometry(310,560,31,31);
    this->zstavka = 0;

}


void Gtn::on_less_button_clicked()
{
    ui->StrelkaLabel_2->setGeometry(390,560,31,31);
    this->zstavka = 1;
}


void Gtn::on_play_button_clicked()
{

    int viigr;
    if (!this->block && this->rstavka > 0 && this->zstavka >= 0 && robuks >= this->rstavka){
        this->block = 1;
        ui->play_button->setDisabled(1);
        if((this->num <= this->now_num && this->zstavka == 1) || (this->num >= this->now_num && this->zstavka == 0)){
            if(this->zstavka){
                robuks += int(round((50./(this->now_num)) * this->rstavka));
                viigr = int(round((50./(this->now_num)) * this->rstavka));
                //ui->text->setText(QString::number((round((50./(100.- this->now_num)) * this->rstavka)) +50.));
            }
            else{
                robuks += int(round((50./(100.- this->now_num)) * this->rstavka));
                viigr = int(round((50./(100.- this->now_num)) * this->rstavka));
                //ui->text->setText(QString::number((round((50./(100.- this->now_num)) * this->rstavka)) +50.));
            }
            ui->text->setText("Ура... Вы выиграли... " + QString::number(viigr)+" робуксов...");
        }
        else{
            ui->text->setText("Вы проиграли...Ха..ха..ха..");
            robuks -= this->rstavka;
        }
        ui->count_robux->setText(QString::number(robuks));

    }
}


void Gtn::on_pushButton_clicked()
{
    emit to_main();
    this->close();
}

