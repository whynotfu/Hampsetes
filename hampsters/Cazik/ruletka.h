#ifndef RULETKA_H
#define RULETKA_H

/*!
 * \file ruletka.h
 * \brief Заголовочный файл класса Ruletka.
 *
 * Этот файл содержит объявление класса Ruletka, который реализует окно игры "Рулетка".
 */

#include <QDialog>

namespace Ui {
    /*!
     * \brief Класс пользовательского интерфейса для Ruletka.
     */
    class Ruletka;
}

/*!
 * \brief Класс Ruletka.
 *
 * Класс Ruletka представляет окно игры "Рулетка", наследуемое от QDialog.
 * Он отвечает за инициализацию и отображение пользовательского интерфейса игры.
 */
class Ruletka : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief Конструктор класса Ruletka.
     *
     * Инициализирует окно игры "Рулетка" и настраивает его пользовательский интерфейс.
     *
     * \param parent Родительский виджет (по умолчанию \c nullptr).
     */
    explicit Ruletka(QWidget *parent = nullptr);

    /*!
     * \brief Деструктор класса Ruletka.
     *
     * Освобождает ресурсы, связанные с пользовательским интерфейсом.
     */
    ~Ruletka();

private:
    Ui::Ruletka *ui; //!< Указатель на объект пользовательского интерфейса.
};

#endif // RULETKA_H
