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
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CasinoMainWindow
{
public:
    QWidget *centralwidget;
    QLabel *MainFon;
    QLabel *ShapkaLabel;
    QLabel *minigamelabel;
    QPushButton *NextGameButton;
    QPushButton *PlayButton;
    QLabel *namelabel;
    QLabel *Profilelabel;
    QPushButton *pushButton;

    void setupUi(QMainWindow *CasinoMainWindow)
    {
        if (CasinoMainWindow->objectName().isEmpty())
            CasinoMainWindow->setObjectName("CasinoMainWindow");
        CasinoMainWindow->resize(800, 600);
        centralwidget = new QWidget(CasinoMainWindow);
        centralwidget->setObjectName("centralwidget");
        MainFon = new QLabel(centralwidget);
        MainFon->setObjectName("MainFon");
        MainFon->setGeometry(QRect(-10, -10, 821, 621));
        ShapkaLabel = new QLabel(centralwidget);
        ShapkaLabel->setObjectName("ShapkaLabel");
        ShapkaLabel->setGeometry(QRect(-10, -10, 821, 61));
        minigamelabel = new QLabel(centralwidget);
        minigamelabel->setObjectName("minigamelabel");
        minigamelabel->setGeometry(QRect(159, 190, 461, 230));
        NextGameButton = new QPushButton(centralwidget);
        NextGameButton->setObjectName("NextGameButton");
        NextGameButton->setGeometry(QRect(550, 450, 61, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Calibri")});
        font.setPointSize(14);
        NextGameButton->setFont(font);
        PlayButton = new QPushButton(centralwidget);
        PlayButton->setObjectName("PlayButton");
        PlayButton->setGeometry(QRect(430, 450, 101, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Calibri")});
        font1.setPointSize(12);
        PlayButton->setFont(font1);
        namelabel = new QLabel(centralwidget);
        namelabel->setObjectName("namelabel");
        namelabel->setGeometry(QRect(220, 70, 329, 109));
        Profilelabel = new QLabel(centralwidget);
        Profilelabel->setObjectName("Profilelabel");
        Profilelabel->setGeometry(QRect(10, 0, 51, 51));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(70, 10, 111, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Calibri")});
        font2.setPointSize(18);
        pushButton->setFont(font2);
        CasinoMainWindow->setCentralWidget(centralwidget);

        retranslateUi(CasinoMainWindow);

        QMetaObject::connectSlotsByName(CasinoMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CasinoMainWindow)
    {
        CasinoMainWindow->setWindowTitle(QCoreApplication::translate("CasinoMainWindow", "MainWindow", nullptr));
        MainFon->setText(QString());
        ShapkaLabel->setText(QString());
        minigamelabel->setText(QString());
        NextGameButton->setText(QCoreApplication::translate("CasinoMainWindow", ">", nullptr));
        PlayButton->setText(QCoreApplication::translate("CasinoMainWindow", "\320\230\320\263\321\200\320\260\321\202\321\214", nullptr));
        namelabel->setText(QString());
        Profilelabel->setText(QString());
        pushButton->setText(QCoreApplication::translate("CasinoMainWindow", "\320\237\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CasinoMainWindow: public Ui_CasinoMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CASINOMAINWINDOW_H
