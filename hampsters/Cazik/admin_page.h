#ifndef ADMIN_PAGE_H
#define ADMIN_PAGE_H

#include <QDialog>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class admin_page;
}

class admin_page : public QDialog
{
    Q_OBJECT

public:
    explicit admin_page(QWidget *parent = nullptr);
    ~admin_page();
    void viewStatistics();
    void slot_show();

private slots:
    // Слот для обработки нажатия кнопки "Пополнить баланс"
    void addMoneyToUser();

private:
    Ui::admin_page *ui;

    // Элементы интерфейса
    QTableWidget *tableWidget; // Таблица для отображения пользователей
    QLineEdit *user_to_send;   // Поле ввода для имени пользователя
    QLineEdit *amount_to_send; // Поле ввода для суммы денег
};

#endif // ADMIN_PAGE_H
