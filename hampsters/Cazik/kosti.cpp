#include "kosti.h"
#include "ui_kosti.h"
#include "client_functions.h"

Kosti::Kosti(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Kosti)
{
    //Добавление всех текстов, кнопочек и тд на форму
    ui->setupUi(this);

    //Установление иконки
    this->setWindowIcon(QIcon(path() + "Images/icon.png"));

    //Установление названия окна
    this->setWindowTitle("Kosti");

    // Делаем окно фиксированным
    this->setFixedSize(800,600);
}

Kosti::~Kosti()
{
    delete ui;
}
