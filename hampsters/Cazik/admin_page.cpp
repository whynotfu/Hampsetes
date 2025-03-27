#include "admin_page.h"
#include "ui_admin_page.h"
#include <QTableWidgetItem>
#include <QDebug>
#include <client_functions.h>

#include <QTableWidgetItem>

admin_page::admin_page(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::admin_page)
{
    ui->setupUi(this);

    // Настройки окна: иконка, название формы, фиксированный размер
    this->setWindowIcon(QIcon(path() + "Images/icon.png"));
    this->setWindowTitle("Admin page");
    this->setFixedSize(700, 450);

    // Заменяем текст картинками
    QPixmap MainFon(path() + "Images/admin_page_back.png");
    ui->MainFon->setPixmap(MainFon);

    // Подключаем кнопку к слоту
    connect(ui->Button_up_balance, &QPushButton::clicked, this, &admin_page::addMoneyToUser);

    // Загружаем статистику (из глобальных данных)
    viewStatistics();
}

admin_page::~admin_page()
{
    delete ui;
}

// Заглушка для просмотра статистики
void admin_page::viewStatistics()
{
    // Очищаем таблицу
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(users.size());

    // Устанавливаем заголовки столбцов
    QStringList headers = {"Логин", "Роль", "Баланс", "Общее кол-во ставок", "Сумма выигрышей", "Последняя авторизация"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // Заполняем таблицу данными из глобальных переменных
    for (int i = 0; i < users.size(); ++i) {
        const User& user = users[i];

        QTableWidgetItem *loginItem = new QTableWidgetItem(user.login);
        QTableWidgetItem *roleItem = new QTableWidgetItem(user.role);
        QTableWidgetItem *balanceItem = new QTableWidgetItem(QString::number(user.balance));
        QTableWidgetItem *betsItem = new QTableWidgetItem(QString::number(user.total_bets));
        QTableWidgetItem *winsItem = new QTableWidgetItem(QString::number(user.total_wins));
        QTableWidgetItem *lastLoginItem = new QTableWidgetItem(user.last_login.toString("yyyy-MM-dd hh:mm:ss"));

        ui->tableWidget->setItem(i, 0, loginItem);
        ui->tableWidget->setItem(i, 1, roleItem);
        ui->tableWidget->setItem(i, 2, balanceItem);
        ui->tableWidget->setItem(i, 3, betsItem);
        ui->tableWidget->setItem(i, 4, winsItem);
        ui->tableWidget->setItem(i, 5, lastLoginItem);
    }
}

// Логика для добавления денег пользователю
void admin_page::addMoneyToUser()
{
    // Получаем данные из полей ввода
    QString username = ui->user_to_send->text();
    QString amountStr = ui->lineEdit_2->text();

    bool ok;
    int amount = amountStr.toInt(&ok);

    if (!ok || amount <= 0) {
        qDebug() << "Invalid amount!";
        return;
    }

    // Находим пользователя в глобальном списке
    int index = -1;
    for (int i = 0; i < users.size(); ++i) {
        if (users[i].login == username) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        // Обновляем баланс пользователя в глобальной переменной
        users[index].balance += amount;
        robuks += amount; // ВРЕМЕННО

        // Обновляем таблицу
        QTableWidgetItem *balanceItem = ui->tableWidget->item(index, 2);
        balanceItem->setText(QString::number(users[index].balance));

        qDebug() << "Added" << amount << "to user:" << username;
    } else {
        qDebug() << "User not found!";
    }
}
