/********************************************************************************
** Form generated from reading UI file 'authregform.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHREGFORM_H
#define UI_AUTHREGFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthRegForm
{
public:
    QLabel *FonLabel;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *RegButton;
    QPushButton *AuthButton;
    QPushButton *ToRegButton;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *LoginLabel;
    QLineEdit *Loginline;
    QLabel *PasswordLabel;
    QLineEdit *Passwordline;
    QLabel *RepeatLabel;
    QLineEdit *Repeatline;
    QLabel *NameLabel;

    void setupUi(QDialog *AuthRegForm)
    {
        if (AuthRegForm->objectName().isEmpty())
            AuthRegForm->setObjectName("AuthRegForm");
        AuthRegForm->resize(400, 300);
        FonLabel = new QLabel(AuthRegForm);
        FonLabel->setObjectName("FonLabel");
        FonLabel->setGeometry(QRect(-10, 0, 411, 311));
        horizontalLayoutWidget = new QWidget(AuthRegForm);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(70, 220, 250, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        RegButton = new QPushButton(horizontalLayoutWidget);
        RegButton->setObjectName("RegButton");

        horizontalLayout->addWidget(RegButton);

        AuthButton = new QPushButton(horizontalLayoutWidget);
        AuthButton->setObjectName("AuthButton");

        horizontalLayout->addWidget(AuthButton);

        ToRegButton = new QPushButton(horizontalLayoutWidget);
        ToRegButton->setObjectName("ToRegButton");

        horizontalLayout->addWidget(ToRegButton);

        formLayoutWidget = new QWidget(AuthRegForm);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(70, 110, 251, 131));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        LoginLabel = new QLabel(formLayoutWidget);
        LoginLabel->setObjectName("LoginLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, LoginLabel);

        Loginline = new QLineEdit(formLayoutWidget);
        Loginline->setObjectName("Loginline");

        formLayout->setWidget(0, QFormLayout::FieldRole, Loginline);

        PasswordLabel = new QLabel(formLayoutWidget);
        PasswordLabel->setObjectName("PasswordLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, PasswordLabel);

        Passwordline = new QLineEdit(formLayoutWidget);
        Passwordline->setObjectName("Passwordline");

        formLayout->setWidget(1, QFormLayout::FieldRole, Passwordline);

        RepeatLabel = new QLabel(formLayoutWidget);
        RepeatLabel->setObjectName("RepeatLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, RepeatLabel);

        Repeatline = new QLineEdit(formLayoutWidget);
        Repeatline->setObjectName("Repeatline");

        formLayout->setWidget(2, QFormLayout::FieldRole, Repeatline);

        NameLabel = new QLabel(AuthRegForm);
        NameLabel->setObjectName("NameLabel");
        NameLabel->setGeometry(QRect(105, 10, 181, 91));

        retranslateUi(AuthRegForm);

        QMetaObject::connectSlotsByName(AuthRegForm);
    } // setupUi

    void retranslateUi(QDialog *AuthRegForm)
    {
        AuthRegForm->setWindowTitle(QCoreApplication::translate("AuthRegForm", "Dialog", nullptr));
        FonLabel->setText(QString());
        RegButton->setText(QCoreApplication::translate("AuthRegForm", "Reg", nullptr));
        AuthButton->setText(QCoreApplication::translate("AuthRegForm", "Auth", nullptr));
        ToRegButton->setText(QCoreApplication::translate("AuthRegForm", "ToReg", nullptr));
        LoginLabel->setText(QCoreApplication::translate("AuthRegForm", "Login", nullptr));
        PasswordLabel->setText(QCoreApplication::translate("AuthRegForm", "Password", nullptr));
        RepeatLabel->setText(QCoreApplication::translate("AuthRegForm", "Repeat password", nullptr));
        NameLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AuthRegForm: public Ui_AuthRegForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHREGFORM_H
