/**
 * @file authregform.h
 * @brief Форма авторизации и регистрации пользователей
 * @author Development Team
 * @date 2025
 * @version 1.0
 * 
 * Этот файл содержит объявление класса AuthRegForm, который управляет
 * процессом входа в систему и регистрации новых пользователей в казино
 * "Хампстерс". Форма взаимодействует с сервером через TCP-соединение
 * для проверки учетных данных и создания новых аккаунтов.
 */

#ifndef AUTHREGFORM_H
#define AUTHREGFORM_H

#include <QObject>
#include <QDialog>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include "clientapi.h"

namespace Ui {
class AuthRegForm;
}

/**
 * @brief Форма авторизации и регистрации пользователей
 * 
 * Класс AuthRegForm предоставляет интерфейс для входа в систему
 * и регистрации новых пользователей. Форма поддерживает:
 * - Авторизацию существующих пользователей
 * - Регистрацию новых аккаунтов
 * - Переключение между режимами входа и регистрации
 * - Сетевое взаимодействие с сервером через TCP
 * - Валидацию введенных данных
 * 
 * После успешной авторизации пользователь получает доступ к
 * основному меню казино и всем его функциям.
 */
class AuthRegForm : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор формы авторизации
     * @param parent Родительский виджет
     */
    explicit AuthRegForm(QWidget *parent = nullptr);
    
    /**
     * @brief Деструктор формы авторизации
     */
    ~AuthRegForm();

    /**
     * @brief Показать форму авторизации
     * 
     * Отображает диалог авторизации и подготавливает интерфейс
     * для ввода учетных данных пользователем
     */
    void slot_show();

private slots:
    /**
     * @brief Обработчик переключения в режим регистрации
     * 
     * Изменяет интерфейс формы для отображения полей регистрации
     * вместо полей авторизации
     */
    void on_ToRegButton_clicked();

    /**
     * @brief Обработчик кнопки "Войти"
     * 
     * Выполняет авторизацию пользователя:
     * - Проверяет заполненность полей логина и пароля
     * - Отправляет запрос на сервер для проверки учетных данных
     * - При успехе открывает главное меню казино
     */
    void on_AuthButton_clicked();

    /**
     * @brief Обработчик кнопки "Зарегистрироваться"
     * 
     * Выполняет регистрацию нового пользователя:
     * - Проверяет корректность введенных данных
     * - Отправляет запрос на создание аккаунта
     * - При успехе автоматически авторизует пользователя
     */
    void on_RegButton_clicked();

private:
    Ui::AuthRegForm *ui; ///< Пользовательский интерфейс формы

    QTcpSocket* socket;  ///< TCP-сокет для связи с сервером
    QByteArray Data;     ///< Буфер для хранения данных сетевого обмена
    
    ClientApi *clientApi; ///< API клиента для взаимодействия с сервером

    /**
     * @brief Управление видимостью элементов при переключении режимов
     * @param visible Показать (true) или скрыть (false) элементы регистрации
     * 
     * Изменяет видимость кнопок и текстовых полей в зависимости
     * от выбранного режима (авторизация или регистрация)
     */
    void set_visible_inReg(bool visible);

    /**
     * @brief Очистить все поля ввода
     * 
     * Удаляет весь введенный пользователем текст из полей
     * логина, пароля и подтверждения пароля
     */
    void clear();

signals:
    /**
     * @brief Сигнал успешной авторизации
     * @param login Логин авторизованного пользователя
     * 
     * Испускается после успешного входа в систему.
     * Передает логин пользователя для дальнейшего использования
     * в основном меню и играх.
     */
    void auth_ok(QString login);

};

#endif // AUTHREGFORM_H

