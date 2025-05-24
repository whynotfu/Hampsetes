#ifndef KLIKER_H
#define KLIKER_H

#include <QDialog>

namespace Ui {
class Kliker;
}

class Kliker : public QDialog
{
    Q_OBJECT

public:
    explicit Kliker(QWidget *parent = nullptr);
    ~Kliker();

    void slot_show();

private slots:
    void on_pushButton_clicked();

    void on_pushButtonTap_clicked();

private:
    Ui::Kliker *ui;

    int Robux100;

signals:
    void to_main();
};

#endif // KLIKER_H
