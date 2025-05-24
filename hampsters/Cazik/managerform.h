/**
 * @file managerform.h
 * @brief Заголовочный файл главного менеджера форм приложения
 * @author Команда разработчиков
 * @date 2025
 * @version 1.0
 * 
 * Содержит объявление класса ManagerForm, который является центральным
 * контроллером всех окон и форм в приложении казино.
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
#include "kosti.h"
#include "admin_page.h"
#include "personal_page.h"

/**
 * @brief Главный менеджер форм приложения казино
 * 
 * Класс ManagerForm является центральным контроллером, который управляет
 * всеми окнами и формами приложения. Он отвечает за:
 * - Инициализацию всех игровых окон
 * - Установку связей между формами через сигналы и слоты
 * - Координацию переходов между различными разделами приложения
 * 
 * Архитектура основана на паттерне "Медиатор", где ManagerForm выступает
 * посредником между всеми формами приложения.
 */
class ManagerForm : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор менеджера форм
     * @param parent Родительский виджет (по умолчанию nullptr)
     * 
     * Инициализирует все формы приложения и устанавливает связи
     * между ними через систему сигналов и слотов Qt.
     */
    ManagerForm(QWidget *parent = nullptr);
    
    /**
     * @brief Деструктор менеджера форм
     * 
     * Освобождает память, занятую всеми формами приложения.
     */
    ~ManagerForm();

private:
    // Основные формы приложения
    
    /** @brief Форма авторизации и регистрации пользователей */
    AuthRegForm* current_auth;
    
    /** @brief Главное меню казино с выбором игр */
    CasinoMainWindow* main_form;
    
    /** @brief Форма игры в слот-машину (барабаны) */
    Baraban* barabanform;
    
    /** @brief Форма игры в рулетку */
    Ruletka* ruletka;
    
    /** @brief Форма игры-кликера */
    Kliker* clicker;
    
    /** @brief Форма игры в кости */
    Kosti* kosti;
    
    /** @brief Форма игры "угадай число" (больше/меньше) */
    Gtn* gtn;
    
    /** @brief Административная панель для управления системой */
    admin_page* adminPanel;
    
    /** @brief Персональная страница пользователя со статистикой */
    personal_page* userPanel;
};

#endif // MANAGERFORM_H
