#include "client_functions.h"
#include <ctime>

#include <QTableWidgetItem>

int robuks;
QString currentUsername;

// Заполняем пользователей
QList<User> users = {
    {
        .login = "bobr",
        .password = "123",
        .role = "admin",
        .balance = 1000,
        .total_bets = 5,
        .total_wins = 200,
        .last_login = QDateTime::currentDateTime(),
        .is_auth = true
    },
    {
        .login = "alice",
        .password = "abc",
        .role = "user",
        .balance = 500,
        .total_bets = 10,
        .total_wins = 100,
        .last_login = QDateTime::currentDateTime(),
        .is_auth = false
    },
    {
        .login = "john",
        .password = "qwerty",
        .role = "user",
        .balance = 2000,
        .total_bets = 0,
        .total_wins = 0,
        .last_login = QDateTime::currentDateTime(),
        .is_auth = true
    }
};

int auth(QString login, QString password)
{
    // Проходим по всем пользователям в глобальном списке
    for (int i = 0; i < users.size(); ++i) {
        if (users[i].login == login && users[i].password == password) {
            // Проверяем роль пользователя
            if (users[i].role == "admin") {
                return 2; // Успешный вход администратора
            } else {
                return 1; // Успешный вход обычного пользователя
            }
        }
    }

    // Если пользователь не найден или данные неверны
    return 3; // Неудачный вход
}

bool reg(QString login, QString password, QString check_password)
{
    // Проверяем, что поля не пустые
    if (login.isEmpty() || password.isEmpty() || check_password.isEmpty()) {
        return false;
    }

    // Проверяем совпадение паролей
    if (password != check_password) {
        return false;
    }

    // Проверяем уникальность логина
    for (const User& user : users) {
        if (user.login == login) {
            return false;
        }
    }

    // Создаем нового пользователя
    User newUser;
    newUser.login = login;
    newUser.password = password;
    newUser.role = "user";         // Новый пользователь всегда имеет роль "user"
    newUser.balance = 0;           // Начальный баланс равен 0
    newUser.total_bets = 0;        // Нет ставок
    newUser.total_wins = 0;        // Нет выигрышей
    newUser.last_login = QDateTime::currentDateTime(); // Текущее время
    newUser.is_auth = false;       // Пользователь еще не авторизован

    // Добавляем нового пользователя в список
    users.append(newUser);

    return true; // Регистрация успешна
}

QString path(){
    return "C:/Users/nasty/Documents/hampst/Hampsetes/hampsters/Cazik/";
}


// Функция возвразающая рандомное число от 1 до 3
int slots_rand(){
    srand(static_cast<unsigned int>(time(0)));

    int num1 = rand() % 3 + 1;
    int num2 = rand() % 3 + 1;
    int num3 = rand() % 3 + 1;

    if (num1 == num2 && num2 == num3){
        if (num1 == 1){
            return 1;
        }
        else if(num1 == 2){
            return 2;
        }
        else{return 3;}
    }
    else{return 0;}

}

// Функция для перемешки массива - нужна исключительно для картинок
void shuffleArray(int* arr, int size) {
    for (int i = size - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        std::swap(arr[i], arr[j]);
    }
}
