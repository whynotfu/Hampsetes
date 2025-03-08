#ifndef MANAGERFORM_H
#define MANAGERFORM_H

#include <QMainWindow>
#include "authregform.h"
#include "casinomainwindow.h"
#include "baraban.h"
#include "ruletka.h"

class ManagerForm : public QMainWindow
{
    Q_OBJECT

public:
    ManagerForm(QWidget *parent = nullptr);
    ~ManagerForm();
private:
    //Тут мы инициализируем все формы
    AuthRegForm* current_auth;
    CasinoMainWindow* main_form;
    Baraban* barabanform;
    Ruletka* ruletka;
};
#endif // MANAGERFORM_H
