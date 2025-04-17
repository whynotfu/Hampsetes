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

    void slot_show();

private:
    Ui::Kosti *ui;

signals:
    void to_main();
};

#endif // KOSTI_H
