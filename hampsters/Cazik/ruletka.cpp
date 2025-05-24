#include "ruletka.h"
#include "ui_ruletka.h"
#include "client_functions.h"
#include <QPainter>

int couner = 0;
bool rotate=false;

Ruletka::Ruletka(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Ruletka)
    , clientApi(ClientApi::getInstance())
{
    ui->setupUi(this);

    //Установление иконки
    this->setWindowIcon(QIcon(path() + "Images/icon.png"));

    //Установление названия окна
    this->setWindowTitle("Ruletka");

    // Делаем окно фиксированным
    this->setFixedSize(800,600);

    //картинка для фона
    QPixmap RuletkaFon(path() + "Images/GamesFon.png");
    ui->Fonlabel->setPixmap(RuletkaFon);

    //картинка самой рулетки
    QPixmap RuletkaObject(path() + "Images/RuletkaObject3.png");
    ui->RuletkaObjectLabell->setPixmap(RuletkaObject);

    //Картинка робуксов
    QPixmap RobuxLabel(path() + "Images/Robux.png");
    ui->label_robux->setPixmap(RobuxLabel);

    ui->label_strel->setPixmap(QPixmap(path()+"Images/StrelkaRuletka.png"));

    this->size_of_stavka = 0;
    this->object_of_stavka = 0;
    std::srand(static_cast<unsigned int>(std::time(0)));
}

void Ruletka::slot_show(){
    this->show();
    ui->count_robux->setText(QString::number(robuks));
}

Ruletka::~Ruletka()
{
    delete ui;
}

void Ruletka::on_BackButton_clicked()
{
    qDebug() << clientApi->toServer(robuks,TotalBets, TotalWins);
    emit to_main();
    this->close();
}


void Ruletka::on_ButtonPlay_clicked()
{
    int num;
    rotate = true;
    if(this->size_of_stavka>0 && robuks>=this->size_of_stavka){
        robuks -=this->size_of_stavka;
        int randomValue = std::rand() % 100 + 1; // Генерируем число от 1 до 100

        if (randomValue <= 48) {
            num = 1; // 48% шанс
            ui->label_text2->setText("Красное");
        } else if (randomValue <= 98 && randomValue>48) {
            num = 2;; // 48% шанс
            ui->label_text2->setText("Черное");
        } else {
            num = 3;; // 2% шанс
            ui->label_text2->setText("Зеленое");
        }
        //------------------------------------------------------
        if (num == this->object_of_stavka){
            ui->label_text->setText("Вы выиграли! ХАРОООШ! ");
            if (num == 1 or num == 2){
                robuks += size_of_stavka*2;
                TotalWins += size_of_stavka*2;
                TotalBets += 1;
            }
            else if(num == 3){
                robuks += size_of_stavka*10;
                TotalWins += size_of_stavka*10;
                TotalBets += 1;

            }
        }
        else{
            ui->label_text->setText("Вы просрали... Лошара! ");
        }
        ui->RuletkaObjectLabell->setPixmap(QPixmap(
            path() + "Images/RuletkaObject"+QString::number(num)+".png"));
        ui->count_robux->setText(QString::number(robuks));
    }
}


void Ruletka::on_ButtonStavka100_clicked()
{
    this->size_of_stavka = 100;

    if(this->object_of_stavka == 1){
        ui->label_text->setText("Ставка: "+QString::number(size_of_stavka)+" на красное.");
    }
    else if(this->object_of_stavka == 2){
        ui->label_text->setText("Ставка: "+QString::number(size_of_stavka)+" на черное.");
    }
    else if(this->object_of_stavka == 3){
        ui->label_text->setText("Ставка: "+QString::number(size_of_stavka)+" на зеленое.");
    }
    else{
        ui->label_text->setText("Ставка: "+QString::number(size_of_stavka));
    }
}


void Ruletka::on_ButtonStavka500_clicked()
{
    this->size_of_stavka = 500;

    if(this->object_of_stavka == 1){
        ui->label_text->setText("Ставка: "+QString::number(size_of_stavka)+" на красное.");
    }
    else if(this->object_of_stavka == 2){
        ui->label_text->setText("Ставка: "+QString::number(size_of_stavka)+" на черное.");
    }
    else if(this->object_of_stavka == 3){
        ui->label_text->setText("Ставка: "+QString::number(size_of_stavka)+" на зеленое.");
    }
    else{
        ui->label_text->setText("Ставка: "+QString::number(size_of_stavka));
    }
}


void Ruletka::on_ButtonStavka1000_clicked()
{
    this->size_of_stavka = 1000;

    if(this->object_of_stavka == 1){
        ui->label_text->setText("Ставка: "+QString::number(size_of_stavka)+" на красное.");
    }
    else if(this->object_of_stavka == 2){
        ui->label_text->setText("Ставка: "+QString::number(size_of_stavka)+" на черное.");
    }
    else if(this->object_of_stavka == 3){
        ui->label_text->setText("Ставка: "+QString::number(size_of_stavka)+" на зеленое.");
    }
    else{
        ui->label_text->setText("Ставка: "+QString::number(size_of_stavka));
    }
}


void Ruletka::on_ButtonStavkaRed_clicked()
{
    this->object_of_stavka = 1;
    ui->label_text->setText("Ставка: "+QString::number(size_of_stavka)+" на красное.");
}


void Ruletka::on_ButtonStavkaBlack_clicked()
{
    this->object_of_stavka = 2;
    ui->label_text->setText("Ставка: "+QString::number(size_of_stavka)+" на черное.");
}


void Ruletka::on_ButtonStavkaGreen_clicked()
{
    this->object_of_stavka = 3;
    ui->label_text->setText("Ставка: "+QString::number(size_of_stavka)+" на зеленое.");
}

