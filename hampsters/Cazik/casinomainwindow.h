#ifndef CASINOMAINWINDOW_H
#define CASINOMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class CasinoMainWindow;
}

class CasinoMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CasinoMainWindow(QWidget *parent = nullptr);
    ~CasinoMainWindow();

private:
    Ui::CasinoMainWindow *ui;

    // Переменная для смены мини-игры
    int game_slot;

    //Объкты, которые нужны для картинок
    QPixmap Image;
    QPixmap Name;
public slots:
    //Показ формы
    void slot_show();

    //Смена картинки мини-игры
    void change_minigame(bool,QPixmap,QPixmap);
private slots:
    //Функции для кнопок
    void on_NextGameButton_clicked();
    void on_PlayButton_clicked();

signals:
    //Сигнал, нунжый для перехода в форму со слотами
    void baraban_sig();


};

#endif // CASINOMAINWINDOW_H
