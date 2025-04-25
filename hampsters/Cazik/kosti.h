#ifndef KOSTI_H
#define KOSTI_H

#include <QDialog>
#include <QPixmap>

namespace Ui {
class Kosti;
}

class Kosti : public QDialog
{
    Q_OBJECT

public:
    explicit Kosti(QWidget *parent = nullptr);
    ~Kosti();
    void slot_show();
    void updateBalance();

private slots:
    void on_pushButtonPlay_clicked();
    void on_pushButton1000_clicked();
    void on_pushButton500_clicked();
    void on_pushButton100_clicked();
    void on_BackButton_clicked();

private:
    Ui::Kosti *ui;
    int size_of_stavka;
    int robuks;
    void rollDice();
    void updateDiceImages(int dice1, int dice2);
    void showResult(int dice1, int dice2);

signals:
    void to_main(QString);
};
#endif // KOSTI_H
