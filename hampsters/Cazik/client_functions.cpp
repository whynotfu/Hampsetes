#include "client_functions.h"
#include <ctime>
#include "clientapi.h"
#include <QTableWidgetItem>

int robuks;
QString currentUsername;
QString currentRole;
int TotalBets;
int TotalWins;
QString ids;

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


QString path(){
    return "C:/Users/golik/OneDrive/Desktop/GotoviKazik/";
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
