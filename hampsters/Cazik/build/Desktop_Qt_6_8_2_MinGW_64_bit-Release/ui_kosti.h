/********************************************************************************
** Form generated from reading UI file 'kosti.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KOSTI_H
#define UI_KOSTI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Kosti
{
public:

    void setupUi(QDialog *Kosti)
    {
        if (Kosti->objectName().isEmpty())
            Kosti->setObjectName("Kosti");
        Kosti->resize(800, 600);

        retranslateUi(Kosti);

        QMetaObject::connectSlotsByName(Kosti);
    } // setupUi

    void retranslateUi(QDialog *Kosti)
    {
        Kosti->setWindowTitle(QCoreApplication::translate("Kosti", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Kosti: public Ui_Kosti {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KOSTI_H
