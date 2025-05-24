#include "client_functions.h"
#include "casinomainwindow.h"
#include "ui_casinomainwindow.h"



CasinoMainWindow::CasinoMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CasinoMainWindow)
{

    // Для смены миниигры
    ui->setupUi(this);

    QPixmap Vlast(path() + "Images/Vlast.png");
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
    QPixmap ProfileIcon2(path() + "Images/Icon2.png");
    ui->Profilelabel->setPixmap(ProfileIcon);

    if (currentRole != "user"){
        ui->Vlast_label->setPixmap(Vlast);
        ui->Profilelabel->setPixmap(ProfileIcon2);
    } else{
        ui->Admin_page_button->setVisible(1);
        }

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
    if(this->game_slot < 0){this->game_slot = 4;}
    else if(this->game_slot > 4){this->game_slot = 0;}

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

    else if(this->game_slot==4)
    {this->Image=QPixmap(path() + "Images/RememberNumber.png");
        this->Name=QPixmap(path() + "Images/TextRememberNumber.png");
    }

    ui->minigamelabel->setPixmap(image);
    ui->namelabel->setPixmap(name);

    QPixmap Vlasts(path() + "Images/VlastInv.png");
    ui->Vlast_label->setPixmap(Vlasts);
}

//функция для прокручивания вперед выбора минигры
void CasinoMainWindow::on_NextGameButton_clicked()
{
    this->change_minigame(true, this->Image, this->Name);
}


//Функция перехода к окну мини-игр
void CasinoMainWindow::on_PlayButton_clicked()
{
    //Выхов окна с угадайкой
    if(this->game_slot==0)
    {
        emit gtn_sig();
        this->close();
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
        emit ruletka_sig();
        this->close();
    }
    //Вызов окна с костями
    else if(this->game_slot==3)
    {
        emit kosti_sig();
        this->close();
    }
    //Вызов окна с кликером
    else if(this->game_slot==4)
    {
        emit clicker_sig();
        this->close();
    }
}


// void CasinoMainWindow::on_Admin_page_button_clicked()
// {
//     admin_page *adminWindow = new admin_page();
//     adminWindow->show();
// }

void CasinoMainWindow::on_Admin_page_button_clicked()
{
    if (currentRole == "admin") {
        emit admn_sig();
    } else {
        QMessageBox::warning(this, "Ошибка", "Доступ запрещен. Вы не являетесь администратором.");
    }
}


void CasinoMainWindow::on_pushButton_clicked()
{
    emit user_sig();
}


void CasinoMainWindow::on_pushButton_2_clicked()
{
    currentRole = "user";
    emit back_sig();
    this->close();
}

