/*!
 * \file authregform.cpp
 * \brief Реализация класса AuthRegForm для авторизации и регистрации.
 *
 * Данный файл содержит реализацию класса AuthRegForm, который отвечает за обработку
 * пользовательского интерфейса для авторизации и регистрации, а также за установление
 * сетевого соединения.
 */

#include "authregform.h"
#include "ui_authregform.h"
#include "client_functions.h"
#include <QPixmap>
#include <QIcon>

/*!
 * \brief Конструктор AuthRegForm.
 *
 * Инициализирует пользовательский интерфейс, устанавливает иконку, заголовок,
 * фиксированный размер окна и начальную конфигурацию видимости элементов.
 *
 * \param parent Родительский виджет.
 */
AuthRegForm::AuthRegForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AuthRegForm)
{
    ui->setupUi(this);

    // Работа с окном: установка иконки, заголовка и фиксированного размера
    this->setWindowIcon(QIcon(path() + "Images/icon.png"));
    this->setWindowTitle("Mega Casino");
    this->setFixedSize(400,300);

    // Установка режима по умолчанию: авторизация (режим регистрации скрыт)
    set_visible_inReg(false);

    // Установка фона в окне авторизации
    QPixmap FonReg(path() + "Images/FonCasinoReg.png");
    ui->FonLabel->setPixmap(FonReg);

    // Установка изображения с названием
    QPixmap NameReg(path() + "Images/Casic.png");
    ui->NameLabel->setPixmap(NameReg);

    // Создание TCP сокета для последующего соединения
    socket = new QTcpSocket(this);
}

/*!
 * \brief Деструктор AuthRegForm.
 *
 * Освобождает ресурсы, связанные с пользовательским интерфейсом.
 */
AuthRegForm::~AuthRegForm()
{
    delete ui;
}

/*!
 * \brief Изменение видимости элементов в зависимости от режима (авторизация/регистрация).
 *
 * Если параметр \a change равен \c true, отображаются элементы для регистрации,
 * если \c false — элементы для авторизации.
 *
 * \param change Режим отображения: \c true для регистрации, \c false для авторизации.
 */
void AuthRegForm::set_visible_inReg(bool change)
{
    ui->RepeatLabel->setVisible(change);
    ui->Repeatline->setVisible(change);
    ui->RegButton->setVisible(change);

    ui->AuthButton->setVisible(!change);
    ui->ToRegButton->setText(change ? "to Auth" : "to Reg");
}

/*!
 * \brief Слот для переключения между режимами авторизации и регистрации.
 *
 * При нажатии на кнопку переключается видимость элементов, отвечающих за регистрацию
 * и авторизацию.
 */
void AuthRegForm::on_ToRegButton_clicked()
{
    set_visible_inReg(!ui->RepeatLabel->isVisible());
}

/*!
 * \brief Слот, обрабатывающий нажатие кнопки авторизации.
 *
 * Если функция \c auth возвращает \c true, устанавливается соединение с сервером,
 * отправляется тестовое сообщение, генерируется сигнал \c auth_ok и окно закрывается.
 * В противном случае вызывается функция \c clear для очистки полей ввода.
 */
void AuthRegForm::on_AuthButton_clicked()
{
    if(auth(ui->Loginline->text(), ui->Passwordline->text())){
        socket->connectToHost("192.168.55.106", 33333);
        QString p = "Удали доту пж";
        socket->write(p.toUtf8());

        emit auth_ok(ui->Loginline->text());
        this->close();
    }
    else {
        clear();
    }
}

/*!
 * \brief Слот, обрабатывающий нажатие кнопки регистрации.
 *
 * Если функция \c reg возвращает \c true, генерируется сигнал \c auth_ok и окно закрывается.
 * Если регистрация не проходит, вызывается функция \c clear для очистки полей ввода.
 */
void AuthRegForm::on_RegButton_clicked()
{
    if(reg(ui->Loginline->text(), ui->Passwordline->text(), ui->Repeatline->text()))
    {
        emit auth_ok(ui->Loginline->text());
        this->close();
    }
    else {
        clear();
    }
}

/*!
 * \brief Очищает поля ввода.
 *
 * Сбрасывает текстовые поля для логина, пароля и повторного ввода пароля.
 */
void AuthRegForm::clear()
{
    ui->Loginline->setText("");
    ui->Passwordline->setText("");
    ui->Repeatline->setText("");
}
