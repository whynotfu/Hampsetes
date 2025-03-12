#ifndef MANAGERFORM_H
#define MANAGERFORM_H

/*!
 * \file managerform.h
 * \brief Заголовочный файл класса ManagerForm.
 *
 * Этот файл содержит объявление класса ManagerForm, который управляет переключением между
 * различными формами приложения: окном регистрации/авторизации, главным окном казино,
 * окном со слотами и окном рулетки.
 */

#include <QMainWindow>
#include "authregform.h"
#include "casinomainwindow.h"
#include "baraban.h"
#include "ruletka.h"

/*!
 * \brief Класс ManagerForm.
 *
 * Менеджер форм отвечает за инициализацию и управление основными окнами приложения.
 * Он создает экземпляры форм для регистрации/авторизации, главного меню казино, слотов и рулетки,
 * а также устанавливает связи между ними посредством сигналов и слотов.
 */
class ManagerForm : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Конструктор класса ManagerForm.
     *
     * Инициализирует все формы приложения и устанавливает связи между сигналами и слотами для
     * перехода между окнами.
     *
     * \param parent Родительский виджет (по умолчанию \c nullptr).
     */
    ManagerForm(QWidget *parent = nullptr);

    /*!
     * \brief Деструктор класса ManagerForm.
     *
     * Освобождает ресурсы, связанные с экземплярами форм.
     */
    ~ManagerForm();

private:
    //! Указатель на окно регистрации/авторизации.
    AuthRegForm* current_auth;

    //! Указатель на главное окно казино.
    CasinoMainWindow* main_form;

    //! Указатель на окно со слотами.
    Baraban* barabanform;

    //! Указатель на окно рулетки.
    Ruletka* ruletka;
};

#endif // MANAGERFORM_H
