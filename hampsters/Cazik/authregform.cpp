#include "authregform.h"
#include "ui_authregform.h"
#include "client_functions.h"
#include <QPixmap>
#include <QIcon>
#include <QMessageBox>
#include "clientapi.h"

AuthRegForm::AuthRegForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AuthRegForm)
    , clientApi(ClientApi::getInstance())

{
    ui->setupUi(this);

    // Настройка окна
    this->setWindowIcon(QIcon(path() + "Images/icon.png"));
    this->setWindowTitle("Mega Casino");
    this->setFixedSize(400, 300);

    set_visible_inReg(false);

    // Фон в логине
    QPixmap FonReg(path() + "Images/FonCasinoReg.png");
    ui->FonLabel->setPixmap(FonReg);

    // Картинка с названием в логине
    QPixmap NameReg(path() + "Images/Casic.png");
    ui->NameLabel->setPixmap(NameReg);

    socket = new QTcpSocket(this);
}

AuthRegForm::~AuthRegForm()
{
    delete ui;
}

// Смена между окнами регистрации и авторизации
void AuthRegForm::set_visible_inReg(bool change)
{
    ui->RepeatLabel->setVisible(change);
    ui->Repeatline->setVisible(change);
    ui->RegButton->setVisible(change);

    ui->AuthButton->setVisible(!change);
    ui->ToRegButton->setText(change ? "to Auth" : "to Reg");
}

void AuthRegForm::on_ToRegButton_clicked()
{
    set_visible_inReg(!ui->RepeatLabel->isVisible());
}

// Логика авторизации
void AuthRegForm::on_AuthButton_clicked()
{
    QString login = ui->Loginline->text();
    QString password = ui->Passwordline->text();

   QString result = clientApi->auth(login, password);

    if (result == "auth+"){ // Успешный вход обычного пользователя
       if (currentRole == "user"){
            QMessageBox::information(this, "Успех", "Вы вошли как обычный пользователь.");
       }
       else{
            QMessageBox::information(this, "Здравствуйте.", "Добро пожаловать, мой господин!");
       }
       emit auth_ok(login); // Передаем сигнал о успешной авторизации
       currentUsername = login; // Сохраняем логин текущего пользователя
       this->close();       // Закрываем форму

    }
    else if (result == "auth-"){
        QMessageBox::critical(this, "Ошибка", "Неверный логин или пароль.");
        clear();
    }
    else{
        QMessageBox::critical(this, "Ошибка", "Неизвестная ошибка авторизации.");
        clear();
    }
}

// Логика регистрации
void AuthRegForm::on_RegButton_clicked()
{
    QString login = ui->Loginline->text();
    QString password = ui->Passwordline->text();
    QString repeatPassword = ui->Repeatline->text();

    QString get = clientApi->reg(login, password, repeatPassword);
    qDebug() << get.split(" ")[0];
    if (get == "reg+") {
        QMessageBox::information(this, "Успех", "Регистрация прошла успешно.");
        set_visible_inReg(!ui->RepeatLabel->isVisible());
    }
    else if (get.split(" ")[0] == "reg-"){
        QMessageBox::warning(this, "Ошибка", "Пароль " + password + " занят пользователем " + get.split(" ")[1]);
    }
    else {
        QMessageBox::warning(this, "Ошибка", "Ошибка регистрации.");
    clear();
    }
}

// Очистка полей ввода
void AuthRegForm::clear()
{
    ui->Loginline->setText("");
    ui->Passwordline->setText("");
    ui->Repeatline->setText("");
}

void AuthRegForm::slot_show(){
    this->show();
}
