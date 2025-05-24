#include "managerform.h"
#include "client_functions.h"

ManagerForm::ManagerForm(QWidget *parent)
    : QMainWindow(parent),
    clientApi(ClientApi::getInstance())
{
    //Инициализация окна с регистрацией / логином
    this->current_auth = new AuthRegForm();

    //Инициализация окна с меню для выбора мини-игр
    this->main_form = new CasinoMainWindow();

    //Инициализация окна со слотами
    this->barabanform = new Baraban();

    //Инициализация окна с рулеткой
    this->ruletka = new Ruletka();

    //Инициализация окна с рулеткой
    this->clicker = new Kliker();

    //Инициализация окна с костями
    this->kosti = new Kosti();

    //Инициализация окна с игрой в больше/меньше
    this->gtn = new Gtn();

    //Инициализация окна с панелью админа
    this->adminPanel = new admin_page();

    //Инициализация окна с панелью Юзера
    this->userPanel = new personal_page();

    //Запуск окна регистрации/логина
    this->current_auth->show();

    // this->adminPanel = new admin_page();          // Админ-панель
    // this->userPanel = new personal_page();        // Пользовательская панель

    //Эта функция для открытия окна от логина/регистрации в меню
    connect(current_auth,&AuthRegForm::auth_ok,main_form,&CasinoMainWindow::slot_show);

    //Эта функция для открытия окна из меню в слоты
    connect(main_form,&CasinoMainWindow::baraban_sig,barabanform,&Baraban::slot_show);

    //Эта функция для открытия окна из меню в рулетку
    connect(main_form,&CasinoMainWindow::ruletka_sig,ruletka,&Ruletka::slot_show);

    //Эта функция для открытия окна из меню в adminku
    connect(main_form,&CasinoMainWindow::admn_sig,adminPanel,&admin_page::slot_show);

    //Эта функция для открытия окна из меню в user page
    connect(main_form,&CasinoMainWindow::user_sig,userPanel,&personal_page::slot_show);

    //Эта функция для открытия окна из меню в кликер
    connect(main_form,&CasinoMainWindow::clicker_sig,clicker,&Kliker::slot_show);

    //Эта функция для выхода из слотов в меню
    connect(barabanform,&Baraban::to_main,main_form,&CasinoMainWindow::slot_show);

    //Эта функция для выхода из рулетки в меню
    connect(ruletka,&Ruletka::to_main,main_form,&CasinoMainWindow::slot_show);

    //Эта функция для выхода из больше-меньше в меню
    connect(gtn,&Gtn::to_main,main_form,&CasinoMainWindow::slot_show);

    //Эта функция для выхода из кликера в меню
    connect(clicker,&Kliker::to_main,main_form,&CasinoMainWindow::slot_show);

    //Эта функция для выхода из kosti в menu
    connect(kosti,&Kosti::to_main,main_form,&CasinoMainWindow::slot_show);

    //Эта функция для открытия окна из меню в кости
    connect(main_form,&CasinoMainWindow::kosti_sig,kosti,&Kosti::slot_show);

    //Эта функция для открытия окна из меню в игру больше/меньше
    connect(main_form,&CasinoMainWindow::gtn_sig,gtn,&Gtn::slot_show);

    connect(main_form,&CasinoMainWindow::back_sig,current_auth,&AuthRegForm::slot_show);
}

ManagerForm::~ManagerForm() {
}
