#ifndef GTN_H
#define GTN_H

#include <QDialog>

namespace Ui {
class Gtn;
}

class Gtn : public QDialog
{
    Q_OBJECT

public:
    explicit Gtn(QWidget *parent = nullptr);
    ~Gtn();
    void slot_show();

private slots:
    void on_new_number_clicked();

    void on_button100_clicked();

    void on_button500_clicked();

    void on_button1000_clicked();

    void on_greater_button_clicked();

    void on_less_button_clicked();

    void on_play_button_clicked();

    void on_pushButton_clicked();

private:
    Ui::Gtn *ui;
    int new_number();
    int num;
    int now_num;
    int block;
    int rstavka;
    int zstavka;

signals:
    void to_main();
};

#endif // GTN_H
