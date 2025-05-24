/**
 * @file managerform.h
 * @brief Главный менеджер форм приложения казино
 * @author Development Team
 * @date 2025
 * @version 1.0
 * 
 * Этот файл содержит объявление класса ManagerForm, который является
 * центральным координатором всех окон и форм в приложении казино "Хампстерс".
 * Менеджер управляет жизненным циклом всех форм, обеспечивает навигацию
 * между ними и координирует взаимодействие различных частей приложения.
 */

#ifndef MANAGERFORM_H
#define MANAGERFORM_H

#include <QMainWindow>
#include "authregform.h"
#include "casinomainwindow.h"
#include "baraban.h"
#include "ruletka.h"
#include "kliker.h"
#include "gtn.h"
#include "clientapi.h"

#include "kosti.h"
#include "admin_page.h"
#include "personal_page.h"


/**
 * @brief Главный менеджер форм и навигации в приложении
 * 
 * Класс ManagerForm служит центральным координатором всего приложения
 * казино "Хампстерс". Он отвечает за:
 * - Создание и управление всеми формами приложения
 * - Обеспечение навигации между различными экранами
 * - Координацию взаимодействия между формами
 * - Управление жизненным циклом игровых окон
 * - Централизованное управление API клиента
 * 
 * Менеджер реализует паттерн "Единая точка входа", обеспечивая
 * согласованное поведение всего приложения и упрощая управление
 * состоянием между различными компонентами.
 * 
 * @example
 * @code
 * // Создание и запуск приложения
 * QApplication app(argc, argv);
 * ManagerForm manager;
 * manager.show();
 * return app.exec();
 * @endcode
 */
class ManagerForm : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор менеджера форм
     * @param parent Родительский виджет
     * 
     * Инициализирует все формы приложения и настраивает
     * связи между ними через систему сигналов и слотов Qt
     */
    ManagerForm(QWidget *parent = nullptr);
    
    /**
     * @brief Деструктор менеджера форм
     * 
     * Освобождает память, занятую всеми управляемыми формами
     * и закрывает соединения с сервером
     */
    ~ManagerForm();

private:
    // Формы пользовательского интерфейса
    AuthRegForm* current_auth;        ///< Форма авторизации и регистрации
    CasinoMainWindow* main_form;      ///< Главное меню казино
    
    // Игровые формы
    Baraban* barabanform;             ///< Игра "Слоты" (игровые автоматы)
    Ruletka* ruletka;                 ///< Игра "Рулетка"
    Kliker* clicker;                  ///< Игра "Кликер" для заработка робуксов
    Kosti* kosti;                     ///< Игра "Кости"
    Gtn* gtn;                         ///< Игра "Угадай число"

    // Панели управления
    admin_page* adminPanel;           ///< Панель администратора для управления системой
    personal_page* userPanel;         ///< Личный кабинет пользователя
    
    // Сетевое взаимодействие
    ClientApi *clientApi;             ///< API для взаимодействия с сервером казино
};
#endif // MANAGERFORM_H
