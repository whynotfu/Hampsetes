/*!
 * \file ruletka.cpp
 * \brief Реализация класса Ruletka.
 *
 * Этот файл содержит реализацию класса Ruletka, представляющего окно игры "Рулетка".
 * На данный момент класс отвечает только за инициализацию пользовательского интерфейса и освобождение ресурсов.
 */

#include "ruletka.h"
#include "ui_ruletka.h"

/*!
 * \brief Конструктор класса Ruletka.
 *
 * Инициализирует окно игры "Рулетка", устанавливая пользовательский интерфейс.
 *
 * \param parent Родительский виджет (по умолчанию \c nullptr).
 */
Ruletka::Ruletka(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Ruletka)
{
    ui->setupUi(this);
}

/*!
 * \brief Деструктор класса Ruletka.
 *
 * Освобождает ресурсы, связанные с пользовательским интерфейсом.
 */
Ruletka::~Ruletka()
{
    delete ui;
}
