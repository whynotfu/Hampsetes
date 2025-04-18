#include "managerform.h"


ManagerForm::ManagerForm(QWidget *parent)
    : QMainWindow(parent)
{
    //Инициализация окна с регистрацией / логином
    this->current_auth = new AuthRegForm();

    //Инициализация окна с меню для выбора мини-игр
    this->main_form = new CasinoMainWindow();

    //Инициализация окна со слотами
    this->barabanform = new Baraban();

    //Инициализация окна с рулеткой
    this->ruletka = new Ruletka();

    //Запуск окна регистрации/логина
    this->current_auth->show();

    //Эта функция для открытия окна от логина/регистрации в меню
    connect(current_auth,&AuthRegForm::auth_ok,main_form,&CasinoMainWindow::slot_show);

    //Эта функция для открытия окна из меню в слоты
    connect(main_form,&CasinoMainWindow::baraban_sig,barabanform,&Baraban::slot_show);

    //Эта функция для выхода из слотов в меню
    connect(barabanform,&Baraban::to_main,main_form,&CasinoMainWindow::slot_show);
}

ManagerForm::~ManagerForm() {}
