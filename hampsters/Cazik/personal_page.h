#ifndef PERSONAL_PAGE_H
#define PERSONAL_PAGE_H

#include <QDialog>

namespace Ui {
class personal_page;
}

class personal_page : public QDialog
{
    Q_OBJECT

public:
    explicit personal_page(QWidget *parent = nullptr);
    void displayUserStatistics(const QString& currentUsername);
    void slot_show();

    ~personal_page();

private:
    Ui::personal_page *ui;
};

#endif // PERSONAL_PAGE_H
