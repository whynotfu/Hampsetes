/********************************************************************************
** Form generated from reading UI file 'baraban.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BARABAN_H
#define UI_BARABAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Baraban
{
public:
    QLabel *Fonlabel;
    QLabel *BarabanObjectLabel;
    QPushButton *pushButtonPlay;
    QPushButton *pushButton100;
    QPushButton *pushButton500;
    QPushButton *pushButton1000;
    QLabel *krutka1;
    QLabel *krutka2;
    QLabel *krutka3;
    QLabel *label_stavka;
    QLabel *label_robux;
    QLabel *count_robux;
    QPushButton *BackButton;

    void setupUi(QDialog *Baraban)
    {
        if (Baraban->objectName().isEmpty())
            Baraban->setObjectName("Baraban");
        Baraban->resize(800, 600);
        Fonlabel = new QLabel(Baraban);
        Fonlabel->setObjectName("Fonlabel");
        Fonlabel->setGeometry(QRect(-5, -5, 811, 611));
        BarabanObjectLabel = new QLabel(Baraban);
        BarabanObjectLabel->setObjectName("BarabanObjectLabel");
        BarabanObjectLabel->setGeometry(QRect(130, 160, 491, 271));
        pushButtonPlay = new QPushButton(Baraban);
        pushButtonPlay->setObjectName("pushButtonPlay");
        pushButtonPlay->setGeometry(QRect(519, 457, 101, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Calibri")});
        font.setPointSize(12);
        pushButtonPlay->setFont(font);
        pushButton100 = new QPushButton(Baraban);
        pushButton100->setObjectName("pushButton100");
        pushButton100->setGeometry(QRect(150, 457, 81, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Calibri")});
        font1.setPointSize(16);
        pushButton100->setFont(font1);
        pushButton500 = new QPushButton(Baraban);
        pushButton500->setObjectName("pushButton500");
        pushButton500->setGeometry(QRect(240, 457, 81, 31));
        pushButton500->setFont(font1);
        pushButton1000 = new QPushButton(Baraban);
        pushButton1000->setObjectName("pushButton1000");
        pushButton1000->setGeometry(QRect(330, 457, 81, 31));
        pushButton1000->setFont(font1);
        krutka1 = new QLabel(Baraban);
        krutka1->setObjectName("krutka1");
        krutka1->setGeometry(QRect(200, 290, 61, 61));
        krutka2 = new QLabel(Baraban);
        krutka2->setObjectName("krutka2");
        krutka2->setGeometry(QRect(310, 290, 61, 61));
        krutka3 = new QLabel(Baraban);
        krutka3->setObjectName("krutka3");
        krutka3->setGeometry(QRect(430, 290, 61, 61));
        label_stavka = new QLabel(Baraban);
        label_stavka->setObjectName("label_stavka");
        label_stavka->setGeometry(QRect(160, 160, 471, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Calibri")});
        font2.setPointSize(22);
        font2.setBold(true);
        font2.setItalic(true);
        label_stavka->setFont(font2);
        label_robux = new QLabel(Baraban);
        label_robux->setObjectName("label_robux");
        label_robux->setGeometry(QRect(750, 10, 41, 41));
        count_robux = new QLabel(Baraban);
        count_robux->setObjectName("count_robux");
        count_robux->setGeometry(QRect(340, 10, 401, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Calibri")});
        font3.setPointSize(20);
        font3.setBold(true);
        count_robux->setFont(font3);
        count_robux->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        count_robux->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        BackButton = new QPushButton(Baraban);
        BackButton->setObjectName("BackButton");
        BackButton->setGeometry(QRect(10, 10, 51, 31));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Calibri")});
        font4.setPointSize(26);
        font4.setBold(true);
        BackButton->setFont(font4);

        retranslateUi(Baraban);

        QMetaObject::connectSlotsByName(Baraban);
    } // setupUi

    void retranslateUi(QDialog *Baraban)
    {
        Baraban->setWindowTitle(QCoreApplication::translate("Baraban", "Dialog", nullptr));
        Fonlabel->setText(QString());
        BarabanObjectLabel->setText(QString());
        pushButtonPlay->setText(QCoreApplication::translate("Baraban", "\320\232\321\200\321\203\321\202\320\270\321\202\321\214", nullptr));
        pushButton100->setText(QCoreApplication::translate("Baraban", "100", nullptr));
        pushButton500->setText(QCoreApplication::translate("Baraban", "500", nullptr));
        pushButton1000->setText(QCoreApplication::translate("Baraban", "1000", nullptr));
        krutka1->setText(QString());
        krutka2->setText(QString());
        krutka3->setText(QString());
        label_stavka->setText(QCoreApplication::translate("Baraban", "\320\241\321\202\320\260\320\262\320\272\320\260: 0", nullptr));
        label_robux->setText(QString());
        count_robux->setText(QString());
        BackButton->setText(QCoreApplication::translate("Baraban", "<-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Baraban: public Ui_Baraban {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BARABAN_H
