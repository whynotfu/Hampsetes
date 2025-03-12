/*!
 * \file managerform.cpp
 * \brief Реализация менеджера форм приложения.
 *
 * Этот файл содержит реализацию класса ManagerForm, который отвечает за инициализацию и переключение
 * между различными окнами приложения: окно регистрации/авторизации, главное окно казино, окно со слотами
 * и окно рулетки.
 */

#include "managerform.h"

/*!
 * \brief Конструктор класса ManagerForm.
 *
 * Инициализирует все окна приложения:
 * - Окно регистрации/авторизации (AuthRegForm)
 * - Главное окно казино (CasinoMainWindow)
 * - Окно со слотами (Baraban)
 * - Окно рулетки (Ruletka)
 *
 * После инициализации окно регистрации/авторизации показывается, а также устанавливаются соединения
 * между сигналами и слотами для переходов между окнами:
 * - При успешной авторизации окно регистрации закрывается, и показывается главное окно казино.
 * - При выборе мини-игры из главного окна казино открывается окно со слотами.
 * - При выходе из окна со слотами осуществляется возврат в главное окно казино.
 *
 * \param parent Родительский виджет (по умолчанию \c nullptr).
 */
ManagerForm::ManagerForm(QWidget *parent)
    : QMainWindow(parent)
{
    // Инициализация окна с регистрацией / логином
    this->current_auth = new AuthRegForm();

    // Инициализация окна с меню для выбора мини-игр
    this->main_form = new CasinoMainWindow();

    // Инициализация окна со слотами
    this->barabanform = new Baraban();

    // Инициализация окна с рулеткой
    this->ruletka = new Ruletka();

    // Запуск окна регистрации/логина
    this->current_auth->show();

    // Соединение сигнала успешной авторизации с показом главного окна казино
    connect(current_auth, &AuthRegForm::auth_ok, main_form, &CasinoMainWindow::slot_show);

    // Соединение сигнала из главного окна с показом окна со слотами
    connect(main_form, &CasinoMainWindow::baraban_sig, barabanform, &Baraban::slot_show);

    // Соединение сигнала выхода из окна со слотами с возвратом в главное окно казино
    connect(barabanform, &Baraban::to_main, main_form, &CasinoMainWindow::slot_show);
}

/*!
 * \brief Деструктор класса ManagerForm.
 *
 * Освобождает ресурсы, связанные с объектом ManagerForm.
 */
ManagerForm::~ManagerForm() {}
