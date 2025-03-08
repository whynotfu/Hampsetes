#include "authregform.h"
#include "ui_authregform.h"
#include "client_functions.h"
#include <QPixmap>
#include <QIcon>

AuthRegForm::AuthRegForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AuthRegForm)
{
    ui->setupUi(this);

    //Работа с окном
    this->setWindowIcon(QIcon(path() + "Images/icon.png"));
    this->setWindowTitle("Mega Casino");
    this->setFixedSize(400,300);

    set_visible_inReg(false);

    //Фон в логине
    QPixmap FonReg(path() + "Images/FonCasinoReg.png");
    ui->FonLabel->setPixmap(FonReg);

    //Картинка с названием в логине
    QPixmap NameReg(path() + "Images/Casic.png");
    ui->NameLabel->setPixmap(NameReg);

    socket = new QTcpSocket(this);



}

AuthRegForm::~AuthRegForm()
{
    delete ui;
}

//Смена с регистрации на логин и наоборот (смотря что занести в функцию)
// change = false, то это окно логина, change = true - окно регистрации
void AuthRegForm::set_visible_inReg(bool change)
{
    ui->RepeatLabel->setVisible(change);
    ui->Repeatline->setVisible(change);
    ui->RegButton->setVisible(change);

    ui->AuthButton->setVisible(!change);
    ui->ToRegButton->setText(change?"to Auth":"to Reg");
}

void AuthRegForm::on_ToRegButton_clicked()
{
    set_visible_inReg(!ui->RepeatLabel->isVisible());
}

//Сам логин (ну когда на кнопку нажали)
void AuthRegForm::on_AuthButton_clicked()
{
    if(auth(ui->Loginline->text(), ui->Passwordline->text())){

        socket->connectToHost("192.168.55.106",33333);
        QString p = "Удали доту пж";
        socket -> write(p.toUtf8());

        emit auth_ok(ui->Loginline->text());////// !!!!!!!!!!!!!
        this->close();
    }
    else{clear();}
}

//Сама регистрация (ну когда на кнопку нажали)
void AuthRegForm::on_RegButton_clicked()
{
    if(reg( ui->Loginline->text(), ui->Passwordline->text(), ui->Repeatline->text()))
    {
        emit auth_ok(ui->Loginline->text());
        this->close();
    }
    else{clear();}
}

//Функция, отчищающая поля ввода
void AuthRegForm::clear()
{
    ui->Loginline->setText("");
    ui->Passwordline->setText("");
    ui->Repeatline->setText("");
}


