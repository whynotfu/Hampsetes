/**
 * @file clientapi.h
 * @brief API клиента для взаимодействия с сервером казино
 * @author Development Team
 * @date 2025
 * @version 1.0
 * 
 * Этот файл содержит объявление класса ClientApi, который реализует
 * единое API для всех сетевых взаимодействий клиента с сервером казино.
 * Использует паттерн Singleton для обеспечения единственного соединения
 * с сервером на протяжении работы приложения.
 */

#ifndef CLIENTAPI_H
#define CLIENTAPI_H

#include <QObject>
#include <QTcpSocket>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>

class ClientApi;

/**
 * @brief Вспомогательный класс для корректного удаления синглтона
 * 
 * Класс SingletonDestroyer обеспечивает правильное освобождение
 * ресурсов синглтона ClientApi при завершении приложения.
 */
class SingletonDestroyer
{
private:
    ClientApi * p_instance; ///< Указатель на экземпляр синглтона

public:
    /**
     * @brief Деструктор, освобождающий ресурсы синглтона
     */
    ~SingletonDestroyer();
    
    /**
     * @brief Инициализация экземпляра для последующего удаления
     * @param p Указатель на экземпляр ClientApi
     */
    void initialize(ClientApi * p);
};


/**
 * @brief Singleton API для сетевого взаимодействия с сервером
 * 
 * Класс ClientApi предоставляет единый интерфейс для всех сетевых
 * операций клиента казино "Хампстерс". Реализует паттерн Singleton
 * для обеспечения единственного TCP-соединения с сервером.
 * 
 * Функциональность включает:
 * - Авторизацию и регистрацию пользователей
 * - Отправку игровых данных и получение результатов
 * - Административные операции
 * - Получение статистики и информации о пользователях
 * - Управление соединением с сервером
 * 
 * @example
 * @code
 * ClientApi* api = ClientApi::getInstance();
 * QString result = api->auth("user", "password");
 * if (result == "OK") {
 *     // Успешная авторизация
 * }
 * @endcode
 */
class ClientApi: public QObject
{
    Q_OBJECT

private:
    static ClientApi * p_instance;    ///< Единственный экземпляр класса
    static SingletonDestroyer destroyer; ///< Объект для корректного удаления синглтона
    QTcpSocket * mTcpSocket;          ///< TCP-сокет для связи с сервером

protected:
    /**
     * @brief Приватный конструктор для реализации паттерна Singleton
     * @param parent Родительский объект Qt
     */
    ClientApi(QObject *parent = nullptr);
    
    ClientApi(const ClientApi&) = delete;            ///< Запрет копирования
    ClientApi& operator = (ClientApi&) = delete;     ///< Запрет присваивания
    
    /**
     * @brief Приватный деструктор
     */
    ~ClientApi();
    
    friend class SingletonDestroyer;

public:
    /**
     * @brief Получить единственный экземпляр ClientApi
     * @return Указатель на экземпляр ClientApi
     * 
     * Создает экземпляр при первом вызове или возвращает существующий
     */
    static ClientApi* getInstance();

public:
    /**
     * @brief Авторизация пользователя на сервере
     * @param login Логин пользователя
     * @param password Пароль пользователя
     * @return Результат авторизации ("OK", "WRONG_PASS", "NO_USER", "ERROR")
     * 
     * Отправляет запрос авторизации на сервер и возвращает результат
     */
    QString auth(QString login, QString password);
    
    /**
     * @brief Регистрация нового пользователя
     * @param login Логин нового пользователя
     * @param password Пароль
     * @param confirmPassword Подтверждение пароля
     * @return Результат регистрации ("OK", "USER_EXISTS", "PASS_MISMATCH", "ERROR")
     * 
     * Создает новый аккаунт пользователя на сервере
     */
    QString reg(QString login, QString password, QString confirmPassword);
    
    /**
     * @brief Отправка произвольного запроса на сервер
     * @param query Строка запроса
     * @return Ответ сервера в виде массива байт
     * 
     * Универсальный метод для отправки любых запросов на сервер
     */
    QByteArray query_to_server(QString query);
    
    /**
     * @brief Получение статистики одного пользователя
     * @param login Логин пользователя
     * @return Строка со статистикой пользователя
     * 
     * Запрашивает детальную статистику указанного пользователя
     */
    QString one_stat(QString login);
    
    /**
     * @brief Отправка результатов игры на сервер
     * @param gameType Тип игры (1-слоты, 2-рулетка, 3-кости, 4-кликер, 5-угадай число)
     * @param betAmount Размер ставки
     * @param winAmount Размер выигрыша (может быть отрицательным при проигрыше)
     * @return Результат операции и обновленный баланс
     * 
     * Обновляет баланс игрока и статистику на основе результатов игры
     */
    QString toServer(int gameType, int betAmount, int winAmount);
    
    /**
     * @brief Административная операция управления балансом
     * @param userLogin Логин пользователя для операции
     * @param operation Тип операции (1-пополнение, 2-списание)
     * @param amount Сумма операции
     * @param adminId ID администратора
     * @return Результат операции
     * 
     * Позволяет администратору изменять баланс пользователей
     */
    QString adminTo(QString userLogin, int operation, int amount, int adminId);

public slots:
    /**
     * @brief Обработчик отключения от сервера
     * 
     * Вызывается при потере соединения с сервером.
     * Выполняет необходимые действия для восстановления соединения
     * или уведомления пользователя о проблеме.
     */
    void slotServerDisconnection();
};


#endif // CLIENTAPI_H
