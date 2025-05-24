#include "admin_page.h"
#include "ui_admin_page.h"
#include <QTableWidgetItem>
#include <QDebug>
#include <client_functions.h>

#include <QTableWidgetItem>

admin_page::admin_page(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::admin_page)
    , clientApi(ClientApi::getInstance())
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
    ui->tableWidget->setRowCount(ids.toInt());

    // Устанавливаем заголовки столбцов
    QStringList headers = {"Логин", "Пароль", "Роль","баланс" ,"Общее кол-во ставок", "Сумма выигрышей"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // Заполняем таблицу данными из глобальных переменных
    for (int i = 0; i < ids.toInt(); ++i) {
        QString get = clientApi->one_stat(QString::number(i + 1));
        qDebug() << get;
        if (get.split(" ")[0] == "UserData+"){
        QString login = get.split(" ")[1];
        QString pass = get.split(" ")[2];
        QString role = get.split(" ")[3];
        QString balance = get.split(" ")[4];
        QString bets = get.split(" ")[5];
        QString wins = get.split(" ")[6];

        QTableWidgetItem *loginItem = new QTableWidgetItem(login);
        QTableWidgetItem *passItem = new QTableWidgetItem(pass);
        QTableWidgetItem *roleItem = new QTableWidgetItem(role);
        QTableWidgetItem *balanceItem = new QTableWidgetItem(QString::number(balance.toInt()));
        QTableWidgetItem *betsItem = new QTableWidgetItem(QString::number(bets.toInt()));
        QTableWidgetItem *winsItem = new QTableWidgetItem(QString::number(wins.toInt()));

        ui->tableWidget->setItem(i, 0, loginItem);
        ui->tableWidget->setItem(i, 1, passItem);
        ui->tableWidget->setItem(i, 2, roleItem);
        ui->tableWidget->setItem(i, 3, balanceItem);
        ui->tableWidget->setItem(i, 4, betsItem);
        ui->tableWidget->setItem(i, 5, winsItem);
        }
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

    clientApi->adminTo(username ,amount, TotalBets, TotalWins);
    this->close();
}

void admin_page::slot_show(){
    viewStatistics();
    this->show();
}
