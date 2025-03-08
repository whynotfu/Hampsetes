#include "ruletka.h"
#include "ui_ruletka.h"
//#include "client_functions.h"

Ruletka::Ruletka(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Ruletka)
{
    ui->setupUi(this);


}

Ruletka::~Ruletka()
{
    delete ui;
}
