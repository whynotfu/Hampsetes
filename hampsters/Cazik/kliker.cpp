#include "kliker.h"
#include "ui_kliker.h"
#include "client_functions.h"

Kliker::Kliker(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Kliker)
{
    ui->setupUi(this);

    //настройки окна: иконка, название формы, фиксированный размер
    this->setWindowIcon(QIcon(path() + "Images/icon.png"));
    this->setWindowTitle("Clicker");
    this->setFixedSize(800,600);

    //картинка для фона
    QPixmap KlikerFon(path() + "Images/GamesFon.png");
    ui->Fonlabel->setPixmap(KlikerFon);

    QPixmap RobuxTapTap(path() + "Images/TapTapRobux.png");
    ui->TapTapRobux->setPixmap(RobuxTapTap);

    //Картинка робуксов
    QPixmap RobuxLabel(path() + "Images/Robux.png");
    ui->label_robux->setPixmap(RobuxLabel);

    this->Robux100 = 0;
}

Kliker::~Kliker()
{
    delete ui;
}

void Kliker::slot_show(){
    this->show();
    ui->count_robux->setText(QString::number(robuks));
}

void Kliker::on_pushButton_clicked()
{
    emit to_main();
    this->close();
}


void Kliker::on_pushButtonTap_clicked()
{
    this->Robux100 += 2;
    if (Robux100 >= 100){
        this->Robux100 = 0;
        robuks += 100;
    }
    ui->count_robux->setText(QString::number(robuks));
    ui->label_robux100->setText(QString::number(this->Robux100)+"/100");
}

