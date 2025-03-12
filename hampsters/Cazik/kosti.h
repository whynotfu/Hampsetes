#ifndef KOSTI_H
#define KOSTI_H

/*!
 * \file kosti.h
 * \brief Заголовочный файл класса Kosti.
 *
 * Этот файл содержит объявление класса Kosti, который реализует окно игры "Kosti".
 */

#include <QDialog>

namespace Ui {
    /*!
     * \brief Класс пользовательского интерфейса для окна Kosti.
     */
    class Kosti;
}

/*!
 * \brief Класс Kosti.
 *
 * Класс Kosti представляет окно игры "Kosti", наследуемое от QDialog.
 * Он отвечает за инициализацию и отображение интерфейса игры.
 */
class Kosti : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief Конструктор класса Kosti.
     *
     * Инициализирует окно игры "Kosti", устанавливая родительский виджет (при наличии)
     * и настраивая элементы пользовательского интерфейса.
     *
     * \param parent Родительский виджет (по умолчанию \c nullptr).
     */
    explicit Kosti(QWidget *parent = nullptr);

    /*!
     * \brief Деструктор класса Kosti.
     *
     * Освобождает ресурсы, связанные с пользовательским интерфейсом.
     */
    ~Kosti();

private:
    Ui::Kosti *ui; //!< Указатель на объект пользовательского интерфейса.
};

#endif // KOSTI_H
