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
    ~Ruletka();

private:
    Ui::Ruletka *ui;
};

#endif // RULETKA_H
