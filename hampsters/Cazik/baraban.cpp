#include "baraban.h"
#include "ui_baraban.h"
#include "client_functions.h"


Baraban::Baraban(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Baraban)
{
    ui->setupUi(this);

    // Настраиваем само коно
    this->setWindowIcon(QIcon(path() + "Images/icon.png"));
    this->setWindowTitle("Baraban");
    this->setFixedSize(800,600);

    //Делаем картиночки из текста
    QPixmap BarabanFon(path() + "Images/GamesFon.png");
    ui->Fonlabel->setPixmap(BarabanFon);

    QPixmap BarabanObj(path() + "Images/BarabanObject.png");
    ui->BarabanObjectLabel->setPixmap(BarabanObj);

    QPixmap RobuxLabel(path() + "Images/Robux.png");
    ui->label_robux->setPixmap(RobuxLabel);

    ui->label_stavka->setText("Ставка: 0");

    this->size_of_stavka = 0;

    //Получаем робуксы
    this->get_robux();
    ui->count_robux->setText(QString::number(this->robux));
}

Baraban::~Baraban()
{
    delete ui;
}

void Baraban::slot_show(){
    this->show();
}

void Baraban::on_pushButtonPlay_clicked()
{
    // Функция рандома для слотов
    if (this->size_of_stavka && this->robux >= this->size_of_stavka){
        // Вот это надо переделать под сервер!!!!!!!!!!
        this->robux -= this->size_of_stavka;
        ui->count_robux->setText(QString::number(this->robux));
        // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        this->run_slots(this->size_of_stavka);
    }
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! - Переделать под сервер
void Baraban::get_robux(){
    this->robux = 1000;
}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void Baraban::run_slots(int size){
    //Берем у сервера информацию он крутке слотов
    int get_num_of_slots = slots_rand();

    //Если полученное число не равно 0 (больше 0) - тут мы выиграли
    if(get_num_of_slots){
        ui->label_stavka->setText("Вы выиграли! +вайбик");
        // Тут выводятся одинаковые картинки (Логично мы же выиграли)
        this->set_item1(get_num_of_slots);
        this->set_item2(get_num_of_slots);
        this->set_item3(get_num_of_slots);

        // Изменить под сервер!!!!!!!!!!!!!!!!!!!
        this->robux += size * 2;
        ui->count_robux->setText(QString::number(this->robux));
        // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }
    // Если получили 0 - то есть просрали
    else{
        ui->label_stavka->setText("Вы просрали! -вайб");
        // Тут просто в слотах выводятся рандомные картинки
        int arr[3] = {1, 2, 3};
        // Функция просто перемешивает массив из трех чисел
        shuffleArray(arr, 3);

        // Меняем картинки
        this->set_item1(arr[0]);
        this->set_item2(arr[1]);
        this->set_item3(arr[2]);

    }
    // Отображаем наши картинки
    ui->krutka1->setPixmap(this->Item1);
    ui->krutka2->setPixmap(this->Item2);
    ui->krutka3->setPixmap(this->Item3);
}

// Эта функция принимает число от 1 до 3 и меняет картинку первого слота
void Baraban::set_item1(int num){
    if (num==1){
        this->Item1=QPixmap(path() + "Images/Item1.png");
    }
    else if (num==2){
        this->Item1=QPixmap(path() + "Images/Item2.png");
    }
    else{this->Item1=QPixmap(path() + "Images/Item3.png");}
}

// Эта функция принимает число от 1 до 3 и меняет картинку второго слота
void Baraban::set_item2(int num){
    if (num==1){
        this->Item2=QPixmap(path() + "Images/Item1.png");
    }
    else if (num==2){
        this->Item2=QPixmap(path() + "Images/Item2.png");
    }
    else{this->Item2=QPixmap(path() + "Images/Item3.png");}
}

// Эта функция принимает число от 1 до 3 и меняет картинку третьего слота
void Baraban::set_item3(int num){
    if (num==1){
        this->Item3=QPixmap(path() + "Images/Item1.png");
    }
    else if (num==2){
        this->Item3=QPixmap(path() + "Images/Item2.png");
    }
    else{this->Item3=QPixmap(path() + "Images/Item3.png");}
}

// Кнопка, для ставки в 1000 робуксов
void Baraban::on_pushButton1000_clicked()
{
    ui->label_stavka->setText("Ставка: 1000");
    this->size_of_stavka = 1000;
}

// Кнопка, для ставки в 500 робуксов
void Baraban::on_pushButton500_clicked()
{
    ui->label_stavka->setText("Ставка: 500");
    this->size_of_stavka = 500;
}

// Кнопка, для ставки в 100 робуксов
void Baraban::on_pushButton100_clicked()
{
    ui->label_stavka->setText("Ставка: 100");
    this->size_of_stavka = 100;
}

// Выход в меню
void Baraban::on_BackButton_clicked()
{
    emit to_main(ui->count_robux->text());
    this->close();
}

