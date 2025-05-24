/**
 * @file managerform.cpp
 * @brief Файл реализации главного менеджера форм приложения
 * @author Команда разработчиков
 * @date 2025
 * @version 1.0
 * 
 * Содержит реализацию класса ManagerForm и всех его методов.
 * Управляет жизненным циклом всех форм приложения и их взаимодействием.
 */

#include "managerform.h"

ManagerForm::ManagerForm(QWidget *parent)
    : QMainWindow(parent)
{
    // Инициализация формы авторизации и регистрации
    this->current_auth = new AuthRegForm();

    // Инициализация главного меню для выбора игр
    this->main_form = new CasinoMainWindow();

    // Инициализация игровых форм
    this->barabanform = new Baraban();    // Слот-машина
    this->ruletka = new Ruletka();        // Рулетка
    this->clicker = new Kliker();         // Кликер
    this->kosti = new Kosti();            // Игра в кости
    this->gtn = new Gtn();                // Игра "больше/меньше"

    // Инициализация панелей управления
    this->adminPanel = new admin_page();      // Админ-панель
    this->userPanel = new personal_page();    // Пользовательская панель

    // Показ начального окна авторизации
    this->current_auth->show();

    // === НАСТРОЙКА СВЯЗЕЙ МЕЖДУ ФОРМАМИ ===
    
    // Переход от авторизации к главному меню
    connect(current_auth, &AuthRegForm::auth_ok, 
            main_form, &CasinoMainWindow::slot_show);

    // Переходы из главного меню в игры
    connect(main_form, &CasinoMainWindow::baraban_sig, 
            barabanform, &Baraban::slot_show);
    
    connect(main_form, &CasinoMainWindow::ruletka_sig, 
            ruletka, &Ruletka::slot_show);
    
    connect(main_form, &CasinoMainWindow::clicker_sig, 
            clicker, &Kliker::slot_show);
    
    connect(main_form, &CasinoMainWindow::kosti_sig, 
            kosti, &Kosti::slot_show);
    
    connect(main_form, &CasinoMainWindow::gtn_sig, 
            gtn, &Gtn::slot_show);

    // Переходы к панелям управления
    connect(main_form, &CasinoMainWindow::admn_sig, 
            adminPanel, &admin_page::slot_show);
    
    connect(main_form, &CasinoMainWindow::user_sig, 
            userPanel, &personal_page::slot_show);

    // Возвраты из игр в главное меню
    connect(barabanform, &Baraban::to_main, 
            main_form, &CasinoMainWindow::slot_show);
    
    connect(ruletka, &Ruletka::to_main, 
            main_form, &CasinoMainWindow::slot_show);
    
    connect(clicker, &Kliker::to_main, 
            main_form, &CasinoMainWindow::slot_show);
    
    connect(gtn, &Gtn::to_main, 
            main_form, &CasinoMainWindow::slot_show);
}

ManagerForm::~ManagerForm() 
{
    // Деструктор - автоматическое освобождение памяти через Qt parent-child систему
}
