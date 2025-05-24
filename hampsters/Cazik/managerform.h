#ifndef MANAGERFORM_H
#define MANAGERFORM_H

#include <QMainWindow>
#include "authregform.h"
#include "casinomainwindow.h"
#include "baraban.h"
#include "ruletka.h"
#include "kliker.h"
#include "gtn.h"

#include "kosti.h"
#include "admin_page.h"
#include "personal_page.h"


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
    Kliker* clicker;
    Kosti* kosti;
    Gtn* gtn;

    admin_page* adminPanel;          // Админ-панель
    personal_page* userPanel;        // Пользовательская панель
};
#endif // MANAGERFORM_H
