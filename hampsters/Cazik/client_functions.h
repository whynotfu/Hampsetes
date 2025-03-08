#ifndef CLIENT_FUNCTIONS_H
#define CLIENT_FUNCTIONS_H
#include <QString>


//Функция логина
bool auth(QString,QString);

//Функция регистрации
bool reg(QString ,QString, QString);

QString path();

//Функция рандома для слотов
int slots_rand();

//Функция, перемешивающая массив. Нужна только для картинок (их рандомного вывода при проигрыше)
void shuffleArray(int*, int);

#endif // CLIENT_FUNCTIONS_H
