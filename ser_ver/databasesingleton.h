/**
 * @file databasesingleton.h
 * @brief Синглтон базы данных для серверной части казино
 * @author Development Team
 * @date 2025
 * @version 1.0
 * 
 * Этот файл содержит объявление серверной версии синглтона базы данных
 * для казино "Хампстерс". Обеспечивает централизованный доступ к данным
 * пользователей, балансам и игровой статистике со стороны сервера.
 */

#ifndef DATABASESINGLETON_H
#define DATABASESINGLETON_H

#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

class DataBaseSingleton;

/**
 * @brief Деструктор синглтона базы данных
 * 
 * Класс DataBaseSingletonDestroyer обеспечивает корректное удаление
 * экземпляра синглтона при завершении работы серверного приложения.
 */
class DataBaseSingletonDestroyer
{
private:
    DataBaseSingleton * p_instance; ///< Указатель на экземпляр синглтона

public:
    /**
     * @brief Деструктор класса-уничтожителя
     */
    ~DataBaseSingletonDestroyer();
    
    /**
     * @brief Инициализация указателя на синглтон
     * @param p Указатель на экземпляр DataBaseSingleton
     */
    void initialize(DataBaseSingleton * p);
};


/**
 * @brief Серверный синглтон для управления базой данных казино
 * 
 * Класс DataBaseSingleton обеспечивает единственную точку доступа
 * к базе данных со стороны сервера. Управляет:
 * - Авторизацией и регистрацией пользователей
 * - Игровыми операциями и обновлением балансов
 * - Получением пользовательских данных и статистики
 * - Административными функциями
 * 
 * Использует SQLite для хранения всех данных казино.
 */
class DataBaseSingleton
{
private:
    static DataBaseSingleton * p_instance;    ///< Единственный экземпляр класса
    static DataBaseSingletonDestroyer destroyer; ///< Объект для корректного удаления
    QSqlDatabase db;                          ///< Соединение с базой данных SQLite

protected:
    /**
     * @brief Приватный конструктор синглтона
     */
    DataBaseSingleton();
    
    DataBaseSingleton(const DataBaseSingleton&) = delete;        ///< Запрет копирования
    DataBaseSingleton& operator = (DataBaseSingleton&) = delete; ///< Запрет присваивания
    
    /**
     * @brief Приватный деструктор
     */
    ~DataBaseSingleton();
    
    friend class DataBaseSingletonDestroyer;

public:
    /**
     * @brief Получить единственный экземпляр синглтона
     * @return Указатель на экземпляр DataBaseSingleton
     */
    static DataBaseSingleton* getInstance();
    
    /**
     * @brief Авторизация пользователя
     * @param login Логин пользователя
     * @param password Пароль пользователя
     * @return Результат авторизации с данными пользователя
     * 
     * Проверяет учетные данные и возвращает информацию о пользователе
     * включая роль и ID при успешной авторизации.
     */
    QString auth(QString login, QString password);
    
    /**
     * @brief Регистрация нового пользователя
     * @param login Логин нового пользователя
     * @param password Пароль нового пользователя
     * @return Результат регистрации
     * 
     * Создает новый аккаунт пользователя с начальным балансом.
     */
    QString reg(QString login, QString password);
    
    /**
     * @brief Операции с балансом пользователя
     * @param operation Тип операции (ставка, выигрыш, административная)
     * @param userId ID пользователя
     * @param amount Сумма операции
     * @param gameType Тип игры для статистики
     * @return Результат операции и обновленный баланс
     * 
     * Обрабатывает все финансовые операции пользователей:
     * ставки, выигрыши, административные начисления/списания.
     */
    QString toAccount(QString operation, QString userId, QString amount, QString gameType);
    
    /**
     * @brief Получение данных пользователя
     * @param userId ID пользователя
     * @return Строка с данными пользователя (баланс, статистика)
     * 
     * Возвращает актуальную информацию о пользователе для отображения
     * в клиентском приложении.
     */
    QString UserData(QString userId);
};
#endif // DATABASESINGLETON_H
