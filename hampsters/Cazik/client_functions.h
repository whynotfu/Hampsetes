#ifndef CLIENT_FUNCTIONS_H
#define CLIENT_FUNCTIONS_H
#include <QString>
#include <QDateTime>

extern int robuks; // Баланс текущего пользователя
extern QString currentUsername; // Логин текущего пользователя

// extern QStringList users; // Список имен пользователей
// extern QList<int> balances; // Список балансов пользователей

// Структура пользователя
struct User {
    QString login;       // Логин пользователя
    QString password;    // Пароль пользователя
    QString role;        // Роль пользователя ("user" или "admin")
    int balance;         // Текущий баланс
    int total_bets;     // Общее количество сделанных ставок
    int total_wins;     // Общая сумма выигрышей
    QDateTime last_login;// Время последней авторизации
    bool is_auth;        // Флаг авторизации
};

// Глобальный список пользователей
extern QList<User> users;

//Функция логина
int auth(QString,QString);

//Функция регистрации
bool reg(QString ,QString, QString);

QString path();

//Функция рандома для слотов
int slots_rand();

//Функция, перемешивающая массив. Нужна только для картинок (их рандомного вывода при проигрыше)
void shuffleArray(int*, int);

#endif // CLIENT_FUNCTIONS_H
