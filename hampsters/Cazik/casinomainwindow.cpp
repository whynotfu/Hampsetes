#include "client_functions.h"
#include "casinomainwindow.h"
#include "ui_casinomainwindow.h"

CasinoMainWindow::CasinoMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CasinoMainWindow)
{

    // Для смены миниигры
    ui->setupUi(this);

    //настройки окна: иконка, название формы, фиксированный размер
    this->setWindowIcon(QIcon(path() + "Images/icon.png"));
    this->setWindowTitle("Menu");
    this->setFixedSize(800,600);

    //Заменяем текст картинками
    QPixmap MainFon(path() + "Images/MainFon.png");
    ui->MainFon->setPixmap(MainFon);

    QPixmap Shapka(path() + "Images/Shapka.png");
    ui->ShapkaLabel->setPixmap(Shapka);\

    QPixmap ProfileIcon(path() + "Images/IconProfile.png");
    ui->Profilelabel->setPixmap(ProfileIcon);


    //Для смены миниигры
    this->game_slot = 2;

}

CasinoMainWindow::~CasinoMainWindow()
{
    delete ui;
}

//Показ формы
void CasinoMainWindow::slot_show()
{
    this->show();
}

// Эта функция меняет картинки мини-игр
void CasinoMainWindow::change_minigame(bool change, QPixmap image, QPixmap name)
{
    //Это вообще не надо, но пусть будет. Тут мы увеличиваем переменную на 1, для смены картинки
    if(change){this->game_slot++;}
    else{this->game_slot--;}

    //Делаем условие чтобы переменная для смены картинки не ушла за рамки
    if(this->game_slot < 0){this->game_slot = 3;}
    else if(this->game_slot > 3){this->game_slot = 0;}

    //Смена картинки и название мини-игры
    if(this->game_slot==0)
    {this->Image=QPixmap(path() + "Images/Baraban.png");
     this->Name=QPixmap(path() + "Images/TextBaraban.png");
    }

    else if(this->game_slot==1)
    {this->Image=QPixmap(path() + "Images/Ruletka.png");
     this->Name=QPixmap(path() + "Images/TextRuletka.png");
    }

    else if(this->game_slot==2)
    {this->Image=QPixmap(path() + "Images/Kosti.png");
     this->Name=QPixmap(path() + "Images/TextKosti.png");
    }

    else if(this->game_slot==3)
    {this->Image=QPixmap(path() + "Images/Kliker.png");
     this->Name=QPixmap(path() + "Images/TextKliker.png");
    }

    ui->minigamelabel->setPixmap(image);
    ui->namelabel->setPixmap(name);
}

//функция для прокручивания вперед выбора минигры
void CasinoMainWindow::on_NextGameButton_clicked()
{
    this->change_minigame(true, this->Image, this->Name);
}


//Функция перехода к окну мини-игр
void CasinoMainWindow::on_PlayButton_clicked()
{
    //Выхов окна с кликером
    if(this->game_slot==0)
    {

    }
    //Вызов окна с барабаном
    else if(this->game_slot==1)
    {
        emit baraban_sig();
        this->close();
    }
    //Вызов окна с рулеткой
    else if(this->game_slot==2)
    {

    }
    //Вызов окна с костями
    else if(this->game_slot==3)
    {

    }
}

