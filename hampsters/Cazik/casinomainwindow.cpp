/*!
 * \file casinomainwindow.cpp
 * \brief Реализация главного окна казино.
 *
 * Данный файл содержит реализацию класса CasinoMainWindow, который управляет главным меню казино.
 * Здесь осуществляется выбор мини-игры, смена изображений и названий мини-игр, а также переход к выбранной игре.
 */

#include "client_functions.h"
#include "casinomainwindow.h"
#include "ui_casinomainwindow.h"

/*!
 * \brief Конструктор CasinoMainWindow.
 *
 * Инициализирует главное окно казино, устанавливая иконку, заголовок, фиксированный размер,
 * а также заменяя текстовые элементы изображениями. Кроме того, задается начальное значение выбора мини-игры.
 *
 * \param parent Родительский виджет (по умолчанию \c nullptr).
 */
CasinoMainWindow::CasinoMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CasinoMainWindow)
{
    // Инициализация пользовательского интерфейса для смены мини-игры
    ui->setupUi(this);

    // Настройка окна: установка иконки, заголовка и фиксированного размера
    this->setWindowIcon(QIcon(path() + "Images/icon.png"));
    this->setWindowTitle("Menu");
    this->setFixedSize(800,600);

    // Замена текстовых элементов изображениями
    QPixmap MainFon(path() + "Images/MainFon.png");
    ui->MainFon->setPixmap(MainFon);

    QPixmap Shapka(path() + "Images/Shapka.png");
    ui->ShapkaLabel->setPixmap(Shapka);

    QPixmap ProfileIcon(path() + "Images/IconProfile.png");
    ui->Profilelabel->setPixmap(ProfileIcon);

    // Устанавливаем начальный индекс выбранной мини-игры
    this->game_slot = 2;
}

/*!
 * \brief Деструктор CasinoMainWindow.
 *
 * Освобождает ресурсы, связанные с пользовательским интерфейсом.
 */
CasinoMainWindow::~CasinoMainWindow()
{
    delete ui;
}

/*!
 * \brief Отображает главное окно казино.
 *
 * Слот для показа главного окна.
 */
void CasinoMainWindow::slot_show()
{
    this->show();
}

/*!
 * \brief Изменяет изображение и название выбранной мини-игры.
 *
 * Функция обновляет индекс выбранной мини-игры (\c game_slot) в зависимости от значения \a change,
 * загружает соответствующие изображения для мини-игры и обновляет элементы интерфейса,
 * отображающие изображение мини-игры и её название.
 *
 * \param change Если \c true, индекс увеличивается; если \c false, индекс уменьшается.
 * \param image QPixmap, представляющий текущее изображение мини-игры.
 * \param name QPixmap, представляющий текущее изображение названия мини-игры.
 */
void CasinoMainWindow::change_minigame(bool change, QPixmap image, QPixmap name)
{
    // Изменяем индекс выбранной мини-игры
    if(change){ this->game_slot++; }
    else{ this->game_slot--; }

    // Корректируем индекс, чтобы он оставался в допустимых пределах [0, 3]
    if(this->game_slot < 0){ this->game_slot = 3; }
    else if(this->game_slot > 3){ this->game_slot = 0; }

    // Обновление изображения и названия мини-игры в зависимости от текущего индекса
    if(this->game_slot == 0)
    {
        this->Image = QPixmap(path() + "Images/Baraban.png");
        this->Name  = QPixmap(path() + "Images/TextBaraban.png");
    }
    else if(this->game_slot == 1)
    {
        this->Image = QPixmap(path() + "Images/Ruletka.png");
        this->Name  = QPixmap(path() + "Images/TextRuletka.png");
    }
    else if(this->game_slot == 2)
    {
        this->Image = QPixmap(path() + "Images/Kosti.png");
        this->Name  = QPixmap(path() + "Images/TextKosti.png");
    }
    else if(this->game_slot == 3)
    {
        this->Image = QPixmap(path() + "Images/Kliker.png");
        this->Name  = QPixmap(path() + "Images/TextKliker.png");
    }

    // Обновляем элементы интерфейса с новыми изображениями
    ui->minigamelabel->setPixmap(image);
    ui->namelabel->setPixmap(name);
}

/*!
 * \brief Обрабатывает нажатие кнопки "Next Game".
 *
 * Вызывает функцию смены мини-игры, передавая текущие изображения.
 */
void CasinoMainWindow::on_NextGameButton_clicked()
{
    this->change_minigame(true, this->Image, this->Name);
}

/*!
 * \brief Обрабатывает нажатие кнопки "Play".
 *
 * В зависимости от выбранной мини-игры, генерирует соответствующий сигнал для перехода
 * к окну выбранной игры. Если выбранная мини-игра не реализована, действие не выполняется.
 */
void CasinoMainWindow::on_PlayButton_clicked()
{
    // Вызов окна с кликером (не реализовано)
    if(this->game_slot == 0)
    {

    }
    // Вызов окна с барабаном
    else if(this->game_slot == 1)
    {
        emit baraban_sig();
        this->close();
    }
    // Вызов окна с рулеткой (не реализовано)
    else if(this->game_slot == 2)
    {

    }
    // Вызов окна с костями (не реализовано)
    else if(this->game_slot == 3)
    {

    }
}
