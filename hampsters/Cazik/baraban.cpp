/*!
 * \file baraban.cpp
 * \brief Реализация игрового окна "Baraban".
 *
 * Этот файл содержит реализацию класса Baraban, реализующего окно игрового автомата,
 * в котором происходит обработка ставок, крутки слотов и отображение результатов.
 */

#include "baraban.h"
#include "ui_baraban.h"
#include "client_functions.h"

/*!
 * \brief Конструктор класса Baraban.
 *
 * Инициализирует окно игры: устанавливает иконку, заголовок, фиксированный размер,
 * загружает изображения для фона, игрового автомата и меток робуксов, а также
 * устанавливает начальные значения для ставки и робуксов.
 *
 * \param parent Родительский виджет (по умолчанию \c nullptr).
 */
Baraban::Baraban(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Baraban)
{
    ui->setupUi(this);

    // Настройка окна: установка иконки, заголовка и фиксированного размера
    this->setWindowIcon(QIcon(path() + "Images/icon.png"));
    this->setWindowTitle("Baraban");
    this->setFixedSize(800,600);

    // Загружаем изображения для фона и объектов
    QPixmap BarabanFon(path() + "Images/GamesFon.png");
    ui->Fonlabel->setPixmap(BarabanFon);

    QPixmap BarabanObj(path() + "Images/BarabanObject.png");
    ui->BarabanObjectLabel->setPixmap(BarabanObj);

    QPixmap RobuxLabel(path() + "Images/Robux.png");
    ui->label_robux->setPixmap(RobuxLabel);

    // Инициализация метки ставки
    ui->label_stavka->setText("Ставка: 0");

    this->size_of_stavka = 0;

    // Получаем начальное количество робуксов
    this->get_robux();
    ui->count_robux->setText(QString::number(this->robux));
}

/*!
 * \brief Деструктор класса Baraban.
 *
 * Освобождает ресурсы, связанные с пользовательским интерфейсом.
 */
Baraban::~Baraban()
{
    delete ui;
}

/*!
 * \brief Отображает окно игры.
 *
 * Слот для показа окна.
 */
void Baraban::slot_show(){
    this->show();
}

/*!
 * \brief Обрабатывает нажатие кнопки "Play".
 *
 * Проверяет, что установлена ставка и достаточно робуксов для игры.
 * При выполнении условий уменьшает баланс робуксов и запускает процесс игры.
 */
void Baraban::on_pushButtonPlay_clicked()
{
    // Функция для генерации случайного результата в слотах
    if (this->size_of_stavka && this->robux >= this->size_of_stavka){
        // Уменьшаем количество робуксов (будет переделано под сервер)
        this->robux -= this->size_of_stavka;
        ui->count_robux->setText(QString::number(this->robux));
        // Запускаем крутку слотов
        this->run_slots(this->size_of_stavka);
    }
}

/*!
 * \brief Получает начальное количество робуксов.
 *
 * В настоящий момент функция устанавливает фиксированное значение робуксов.
 * (Будет переделано для работы с сервером)
 */
void Baraban::get_robux(){
    this->robux = 1000;
}

/*!
 * \brief Запускает процесс игры в слоты.
 *
 * Получает результат крутки слотов (через функцию slots_rand) и в зависимости от результата:
 * - При выигрыше устанавливает одинаковые изображения слотов и начисляет выигрыш;
 * - При проигрыше перемешивает изображения.
 *
 * \param size Размер ставки.
 */
void Baraban::run_slots(int size){
    // Получаем результат крутки слотов от сервера
    int get_num_of_slots = slots_rand();

    // Если результат больше 0 — игрок выигрывает
    if(get_num_of_slots){
        ui->label_stavka->setText("Вы выиграли! +вайбик");
        // Отображаем выигрышные картинки во всех слотах
        this->set_item1(get_num_of_slots);
        this->set_item2(get_num_of_slots);
        this->set_item3(get_num_of_slots);

        // Начисляем выигрыш (будет переработано под сервер)
        this->robux += size * 2;
        ui->count_robux->setText(QString::number(this->robux));
    }
    // Если результат равен 0 — игрок проигрывает
    else{
        ui->label_stavka->setText("Вы просрали! -вайб");
        // Массив для случайного перемешивания изображений
        int arr[3] = {1, 2, 3};
        // Перемешиваем массив
        shuffleArray(arr, 3);

        // Обновляем изображения слотов согласно перемешанному массиву
        this->set_item1(arr[0]);
        this->set_item2(arr[1]);
        this->set_item3(arr[2]);
    }
    // Отображаем итоговые изображения слотов
    ui->krutka1->setPixmap(this->Item1);
    ui->krutka2->setPixmap(this->Item2);
    ui->krutka3->setPixmap(this->Item3);
}

/*!
 * \brief Устанавливает изображение для первого слота.
 *
 * Принимает число от 1 до 3 и устанавливает соответствующее изображение.
 *
 * \param num Число, определяющее, какое изображение установить (1, 2 или 3).
 */
void Baraban::set_item1(int num){
    if (num==1){
        this->Item1 = QPixmap(path() + "Images/Item1.png");
    }
    else if (num==2){
        this->Item1 = QPixmap(path() + "Images/Item2.png");
    }
    else{
        this->Item1 = QPixmap(path() + "Images/Item3.png");
    }
}

/*!
 * \brief Устанавливает изображение для второго слота.
 *
 * Принимает число от 1 до 3 и устанавливает соответствующее изображение.
 *
 * \param num Число, определяющее, какое изображение установить (1, 2 или 3).
 */
void Baraban::set_item2(int num){
    if (num==1){
        this->Item2 = QPixmap(path() + "Images/Item1.png");
    }
    else if (num==2){
        this->Item2 = QPixmap(path() + "Images/Item2.png");
    }
    else{
        this->Item2 = QPixmap(path() + "Images/Item3.png");
    }
}

/*!
 * \brief Устанавливает изображение для третьего слота.
 *
 * Принимает число от 1 до 3 и устанавливает соответствующее изображение.
 *
 * \param num Число, определяющее, какое изображение установить (1, 2 или 3).
 */
void Baraban::set_item3(int num){
    if (num==1){
        this->Item3 = QPixmap(path() + "Images/Item1.png");
    }
    else if (num==2){
        this->Item3 = QPixmap(path() + "Images/Item2.png");
    }
    else{
        this->Item3 = QPixmap(path() + "Images/Item3.png");
    }
}

/*!
 * \brief Обрабатывает нажатие кнопки для ставки в 1000 робуксов.
 *
 * Устанавливает размер ставки равным 1000 и обновляет соответствующую метку.
 */
void Baraban::on_pushButton1000_clicked()
{
    ui->label_stavka->setText("Ставка: 1000");
    this->size_of_stavka = 1000;
}

/*!
 * \brief Обрабатывает нажатие кнопки для ставки в 500 робуксов.
 *
 * Устанавливает размер ставки равным 500 и обновляет соответствующую метку.
 */
void Baraban::on_pushButton500_clicked()
{
    ui->label_stavka->setText("Ставка: 500");
    this->size_of_stavka = 500;
}

/*!
 * \brief Обрабатывает нажатие кнопки для ставки в 100 робуксов.
 *
 * Устанавливает размер ставки равным 100 и обновляет соответствующую метку.
 */
void Baraban::on_pushButton100_clicked()
{
    ui->label_stavka->setText("Ставка: 100");
    this->size_of_stavka = 100;
}

/*!
 * \brief Обрабатывает нажатие кнопки "Back".
 *
 * Генерирует сигнал \c to_main с текущим количеством робуксов и закрывает окно.
 */
void Baraban::on_BackButton_clicked()
{
    emit to_main(ui->count_robux->text());
    this->close();
}
