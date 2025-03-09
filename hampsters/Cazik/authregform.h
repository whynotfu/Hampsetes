#ifndef AUTHREGFORM_H
#define AUTHREGFORM_H

#include <QObject>
#include <QDialog>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>



namespace Ui {
class AuthRegForm;
}

class AuthRegForm : public QDialog
{
    Q_OBJECT

public:
    explicit AuthRegForm(QWidget *parent = nullptr);
    ~AuthRegForm();

private slots:
    //Функции для кнопок
    void on_ToRegButton_clicked();

    void on_AuthButton_clicked();

    void on_RegButton_clicked();

private:
    Ui::AuthRegForm *ui;

    QTcpSocket* socket;
    QByteArray Data;
    //Функция для убирания кнопок и текста при нажатии на to_reg
    void set_visible_inReg(bool);

    //Стирает вводимый текст
    void clear();
signals:
    // Сигнад, который нужен, чтобы открыть форму с меню
    void auth_ok(QString);
};

#endif // AUTHREGFORM_H

