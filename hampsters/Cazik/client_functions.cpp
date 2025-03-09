#include "client_functions.h"
#include <ctime>

bool auth(QString login,QString password)
{
    //Заглушка для логина

    if(login=="bobr" && password=="123"){return true;}
    else{return false;}
}

bool reg(QString login,QString password, QString check_password)
{
    //Заглушка для регистра
    if(login==""||password==""||check_password==""){return false;}
    if(login!="bobr" && password == check_password){return true;}
    else{return false;}
}

QString path(){
    return "C:/Desktop/Desktop/CasinoQt/Cazik/";
}


// Функция возвразающая рандомное число от 1 до 3
int slots_rand(){
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
