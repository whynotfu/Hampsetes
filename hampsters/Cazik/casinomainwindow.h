#ifndef CASINOMAINWINDOW_H
#define CASINOMAINWINDOW_H

/*!
 * \file casinomainwindow.h
 * \brief Заголовочный файл главного окна казино.
 *
 * Данный файл содержит объявление класса CasinoMainWindow, который реализует главное окно
 * казино. Оно позволяет пользователю выбирать мини-игры, отображать соответствующие изображения
 * и переходить к игровым формам.
 */

#include <QMainWindow>
#include <QPixmap>

namespace Ui {
    /*!
     * \brief Класс пользовательского интерфейса для CasinoMainWindow.
     */
    class CasinoMainWindow;
}

/*!
 * \brief Класс CasinoMainWindow.
 *
 * Основное окно казино, предоставляющее возможность выбора мини-игр, отображения их изображений
 * и перехода к соответствующим игровым окнам.
 */
class CasinoMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Конструктор CasinoMainWindow.
     *
     * Инициализирует главное окно казино, устанавливая необходимые параметры, и настраивает
     * пользовательский интерфейс.
     *
     * \param parent Родительский виджет (по умолчанию \c nullptr).
     */
    explicit CasinoMainWindow(QWidget *parent = nullptr);

    /*!
     * \brief Деструктор CasinoMainWindow.
     *
     * Освобождает выделенные ресурсы.
     */
    ~CasinoMainWindow();

private:
    Ui::CasinoMainWindow *ui; //!< Указатель на пользовательский интерфейс главного окна казино.

    /*!
     * \brief Индекс выбранной мини-игры.
     *
     * Используется для определения текущей мини-игры при переключении между ними.
     */
    int game_slot;

    /*!
     * \brief Изображение мини-игры.
     */
    QPixmap Image;

    /*!
     * \brief Изображение названия мини-игры.
     */
    QPixmap Name;

public slots:
    /*!
     * \brief Отображает главное окно казино.
     *
     * Слот для показа главного окна.
     */
    void slot_show();

    /*!
     * \brief Изменяет изображение и название выбранной мини-игры.
     *
     * Функция обновляет отображаемые изображения мини-игры и её названия в зависимости от
     * направления изменения.
     *
     * \param change Логическое значение, определяющее направление смены (true - следующая, false - предыдущая).
     * \param image Новое изображение мини-игры.
     * \param name Новое изображение названия мини-игры.
     */
    void change_minigame(bool change, QPixmap image, QPixmap name);

private slots:
    /*!
     * \brief Обрабатывает нажатие кнопки для перехода к следующей мини-игре.
     *
     * Вызывает функцию смены мини-игры для обновления изображений.
     */
    void on_NextGameButton_clicked();

    /*!
     * \brief Обрабатывает нажатие кнопки "Play".
     *
     * Инициирует переход к выбранной мини-игре.
     */
    void on_PlayButton_clicked();

signals:
    /*!
     * \brief Сигнал для перехода к окну со слотами.
     *
     * Генерируется при выборе соответствующей мини-игры, например, барабана.
     */
    void baraban_sig();
};

#endif // CASINOMAINWINDOW_H
