/*!
 * \file kosti.cpp
 * \brief Реализация класса Kosti.
 *
 * Этот файл содержит реализацию класса Kosti, который отвечает за окно игры "Kosti".
 * Окно устанавливает иконку, заголовок и фиксированный размер.
 */

#include "kosti.h"
#include "ui_kosti.h"
#include "client_functions.h"

/*!
 * \brief Конструктор класса Kosti.
 *
 * Инициализирует окно игры "Kosti", устанавливая все необходимые элементы интерфейса,
 * такие как иконка, заголовок окна и фиксированный размер. Для установки иконки используется
 * функция \c path(), которая возвращает путь к ресурсам.
 *
 * \param parent Родительский виджет (по умолчанию \c nullptr).
 */
Kosti::Kosti(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Kosti)
{
    // Добавление всех текстов, кнопочек и т.д. на форму
    ui->setupUi(this);

    // Установление иконки
    this->setWindowIcon(QIcon(path() + "Images/icon.png"));

    // Установление названия окна
    this->setWindowTitle("Kosti");

    // Делаем окно фиксированным
    this->setFixedSize(800,600);
}

/*!
 * \brief Деструктор класса Kosti.
 *
 * Освобождает ресурсы, связанные с пользовательским интерфейсом.
 */
Kosti::~Kosti()
{
    delete ui;
}
