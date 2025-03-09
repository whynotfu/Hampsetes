/********************************************************************************
** Form generated from reading UI file 'ruletka.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RULETKA_H
#define UI_RULETKA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Ruletka
{
public:
    QLabel *Fonlabel;

    void setupUi(QDialog *Ruletka)
    {
        if (Ruletka->objectName().isEmpty())
            Ruletka->setObjectName("Ruletka");
        Ruletka->resize(800, 600);
        Fonlabel = new QLabel(Ruletka);
        Fonlabel->setObjectName("Fonlabel");
        Fonlabel->setGeometry(QRect(-10, -10, 821, 621));

        retranslateUi(Ruletka);

        QMetaObject::connectSlotsByName(Ruletka);
    } // setupUi

    void retranslateUi(QDialog *Ruletka)
    {
        Ruletka->setWindowTitle(QCoreApplication::translate("Ruletka", "Dialog", nullptr));
        Fonlabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Ruletka: public Ui_Ruletka {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RULETKA_H
