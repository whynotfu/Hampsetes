#ifndef RULETKA_H
#define RULETKA_H

#include <QDialog>

namespace Ui {
class Ruletka;
}

class Ruletka : public QDialog
{
    Q_OBJECT

public:
    explicit Ruletka(QWidget *parent = nullptr);
    void slot_show();
    ~Ruletka();

private slots:
    void on_BackButton_clicked();

    void on_ButtonPlay_clicked();

    void on_ButtonStavka100_clicked();

    void on_ButtonStavka500_clicked();

    void on_ButtonStavka1000_clicked();

    void on_ButtonStavkaRed_clicked();

    void on_ButtonStavkaBlack_clicked();

    void on_ButtonStavkaGreen_clicked();


private:
    Ui::Ruletka *ui;

    int size_of_stavka;
    int object_of_stavka;

signals:
    void to_main();
};

#endif // RULETKA_H
