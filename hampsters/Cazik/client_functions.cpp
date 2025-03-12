/*!
 * \file client_functions.cpp
 * \brief Реализация вспомогательных функций для казино.
 *
 * Этот файл содержит реализации функций для авторизации, регистрации,
 * получения пути к ресурсам, генерации случайного числа для игровых слотов
 * и перемешивания массива.
 */

#include "client_functions.h"
#include <ctime>
#include <algorithm>

/*!
 * \brief Проверяет корректность данных для авторизации.
 *
 * Функция служит заглушкой для проверки авторизации пользователя.
 * Возвращает \c true, если логин равен "bobr" и пароль равен "123", иначе — \c false.
 *
 * \param login Логин пользователя.
 * \param password Пароль пользователя.
 * \return \c true, если данные авторизации корректны, иначе \c false.
 */
bool auth(QString login, QString password)
{
    if(login == "bobr" && password == "123")
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*!
 * \brief Проверяет корректность данных для регистрации.
 *
 * Функция служит заглушкой для регистрации пользователя.
 * Если одно из полей (логин, пароль или проверка пароля) пустое, возвращается \c false.
 * Если логин не равен "bobr" и пароль совпадает с подтверждением, возвращается \c true.
 *
 * \param login Логин пользователя.
 * \param password Пароль пользователя.
 * \param check_password Подтверждение пароля.
 * \return \c true, если регистрация может быть выполнена, иначе \c false.
 */
bool reg(QString login, QString password, QString check_password)
{
    if(login == "" || password == "" || check_password == "")
    {
        return false;
    }
    if(login != "bobr" && password == check_password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*!
 * \brief Возвращает путь к ресурсам.
 *
 * Функция возвращает строку с путем к директории, где хранятся ресурсы казино.
 *
 * \return Строка, содержащая путь к ресурсам.
 */
QString path()
{
    return "C:/Desktop/Desktop/CasinoQt/Cazik/";
}

/*!
 * \brief Генерирует случайное число для игровых слотов.
 *
 * Функция генерирует три случайных числа в диапазоне от 1 до 3.
 * Если все три числа равны, возвращается это число (1, 2 или 3).
 * Если хотя бы одно число отличается от других, возвращается 0.
 *
 * \return Случайное число от 1 до 3, если все числа совпадают, иначе 0.
 */
int slots_rand()
{
    int num1 = rand() % 3 + 1;
    int num2 = rand() % 3 + 1;
    int num3 = rand() % 3 + 1;

    if (num1 == num2 && num2 == num3)
    {
        if (num1 == 1)
        {
            return 1;
        }
        else if(num1 == 2)
        {
            return 2;
        }
        else
        {
            return 3;
        }
    }
    else
    {
        return 0;
    }
}

/*!
 * \brief Перемешивает элементы массива.
 *
 * Функция реализует алгоритм Фишера–Йетса для случайного перемешивания
 * массива целых чисел. Используется исключительно для изменения порядка картинок.
 *
 * \param arr Указатель на массив целых чисел.
 * \param size Размер массива.
 */
void shuffleArray(int* arr, int size)
{
    for (int i = size - 1; i > 0; --i)
    {
        int j = rand() % (i + 1);
        std::swap(arr[i], arr[j]);
    }
}
