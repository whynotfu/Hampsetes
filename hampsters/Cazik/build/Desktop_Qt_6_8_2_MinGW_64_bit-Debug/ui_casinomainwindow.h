/********************************************************************************
** Form generated from reading UI file 'casinomainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CASINOMAINWINDOW_H
#define UI_CASINOMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CasinoMainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuxX_Casino_Xx;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CasinoMainWindow)
    {
        if (CasinoMainWindow->objectName().isEmpty())
            CasinoMainWindow->setObjectName("CasinoMainWindow");
        CasinoMainWindow->resize(800, 600);
        centralwidget = new QWidget(CasinoMainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 530, 80, 18));
        CasinoMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CasinoMainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        menuxX_Casino_Xx = new QMenu(menubar);
        menuxX_Casino_Xx->setObjectName("menuxX_Casino_Xx");
        CasinoMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(CasinoMainWindow);
        statusbar->setObjectName("statusbar");
        CasinoMainWindow->setStatusBar(statusbar);

        menubar->addAction(menuxX_Casino_Xx->menuAction());

        retranslateUi(CasinoMainWindow);

        QMetaObject::connectSlotsByName(CasinoMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CasinoMainWindow)
    {
        CasinoMainWindow->setWindowTitle(QCoreApplication::translate("CasinoMainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("CasinoMainWindow", "Exit", nullptr));
        menuxX_Casino_Xx->setTitle(QCoreApplication::translate("CasinoMainWindow", "xX_Casino_Xx", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CasinoMainWindow: public Ui_CasinoMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CASINOMAINWINDOW_H
