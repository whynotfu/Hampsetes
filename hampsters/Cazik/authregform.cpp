/**
 * @file authregform.cpp
 * @brief Реализация формы авторизации и регистрации
 * @author Команда разработчиков
 * @date 2025
 * @version 1.0
 * 
 * Содержит реализацию класса AuthRegForm для аутентификации пользователей
 * и регистрации новых аккаунтов в системе казино.
 */

#include "authregform.h"
#include "ui_authregform.h"
#include "client_functions.h"
#include <QPixmap>
#include <QIcon>
#include <QMessageBox>

AuthRegForm::AuthRegForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AuthRegForm)
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

    int result = auth(login, password);

    switch (result) {
    case 1: // Успешный вход обычного пользователя
        QMessageBox::information(this, "Успех", "Вы вошли как обычный пользователь.");
        emit auth_ok(login); // Передаем сигнал о успешной авторизации
        currentUsername = login; // Сохраняем логин текущего пользователя
        this->close();       // Закрываем форму
        break;

    case 2: // Успешный вход администратора
        QMessageBox::information(this, "Успех", "Вы вошли как администратор.");
        emit auth_ok(login); // Передаем сигнал о успешной авторизации
        currentUsername = login; // Сохраняем логин текущего пользователя
        this->close();       // Закрываем форму
        break;

    case 3: // Неудачная авторизация
        QMessageBox::warning(this, "Ошибка", "Неверный логин или пароль.");
        clear(); // Очищаем поля ввода
        break;

    default:
        QMessageBox::critical(this, "Ошибка", "Неизвестная ошибка авторизации.");
        clear(); // Очищаем поля ввода
        break;
    }
}

// Логика регистрации
void AuthRegForm::on_RegButton_clicked()
{
    QString login = ui->Loginline->text();
    QString password = ui->Passwordline->text();
    QString repeatPassword = ui->Repeatline->text();

    if (reg(login, password, repeatPassword)) {
        QMessageBox::information(this, "Успех", "Регистрация прошла успешно.");
        emit auth_ok(login); // Передаем сигнал о успешной регистрации
        this->close();       // Закрываем форму
    } else {
        QMessageBox::warning(this, "Ошибка", "Ошибка регистрации.");
        clear(); // Очищаем поля ввода
    }
}

// Очистка полей ввода
void AuthRegForm::clear()
{
    ui->Loginline->setText("");
    ui->Passwordline->setText("");
    ui->Repeatline->setText("");
}
