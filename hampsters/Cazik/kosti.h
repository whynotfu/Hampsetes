#ifndef KOSTI_H
#define KOSTI_H

#include <QDialog>

namespace Ui {
class Kosti;
}

class Kosti : public QDialog
{
    Q_OBJECT

public:
    explicit Kosti(QWidget *parent = nullptr);
    ~Kosti();

private:
    Ui::Kosti *ui;
};

#endif // KOSTI_H
