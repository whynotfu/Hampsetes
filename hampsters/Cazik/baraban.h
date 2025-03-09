#ifndef BARABAN_H
#define BARABAN_H

#include <QDialog>
namespace Ui {
class Baraban;
}

class Baraban : public QDialog
{
    Q_OBJECT

public:
    explicit Baraban(QWidget *parent = nullptr);
    ~Baraban();
    //Функция запуска формы
    void slot_show();

    //Функции для смены картинок в слотах
    void set_item1(int);
    void set_item2(int);
    void set_item3(int);

private slots:
    //Функции для кнопок
    void on_pushButtonPlay_clicked();

    void on_pushButton1000_clicked();

    void on_pushButton500_clicked();

    void on_pushButton100_clicked();

    void on_BackButton_clicked();

private:
    Ui::Baraban *ui;

    //Объукты, которые нужны для замены текста (label) картинкой
    QPixmap Item1;
    QPixmap Item2;
    QPixmap Item3;

    // Размер ставки (100, 500, 1000)
    int size_of_stavka;

    // деньги мани кеш
    int robux;

    // Крутка слотов
    void run_slots(int);

    // Получение денег с базы данных (Это потом сделать надо будет)
    void get_robux();

signals:
    // Сигнал для возврата в меню
    void to_main(QString);

};

#endif // BARABAN_H
