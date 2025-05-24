QT       += core gui network
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin_page.cpp \
    authregform.cpp \
    baraban.cpp \
    casinomainwindow.cpp \
    client_functions.cpp \
    clientapi.cpp \
    gtn.cpp \
    kliker.cpp \
    kosti.cpp \
    main.cpp \
    managerform.cpp \
    personal_page.cpp \
    ruletka.cpp

HEADERS += \
    admin_page.h \
    authregform.h \
    baraban.h \
    casinomainwindow.h \
    client_functions.h \
    clientapi.h \
    gtn.h \
    kliker.h \
    kosti.h \
    managerform.h \
    personal_page.h \
    ruletka.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    admin_page.ui \
    authregform.ui \
    baraban.ui \
    casinomainwindow.ui \
    gtn.ui \
    kliker.ui \
    kosti.ui \
    personal_page.ui \
    ruletka.ui

DISTFILES += \
    Images/Baraban.png \
    Images/BarabanObject.png \
    Images/Casic.png \
    Images/FonCasinoReg.png \
    Images/GamesFon.png \
    Images/Icon2.png \
    Images/IconProfile.png \
    Images/Item1.png \
    Images/Item2.png \
    Images/Item3.png \
    Images/Kliker.png \
    Images/Kosti.png \
    Images/KostiFIve.png \
    Images/KostiFour.png \
    Images/KostiN.png \
    Images/KostiOne.png \
    Images/KostiSix.png \
    Images/KostiThree.png \
    Images/KostiTwo.png \
    Images/MainFon.png \
    Images/RememberNumber.png \
    Images/Robux.png \
    Images/Ruletka.png \
    Images/RuletkaObject1.png \
    Images/RuletkaObject2.png \
    Images/RuletkaObject3.png \
    Images/Shapka.png \
    Images/Strelka.png \
    Images/Strelka2.png \
    Images/StrelkaRuletka.png \
    Images/TapTapRobux.png \
    Images/TextBaraban.png \
    Images/TextKliker.png \
    Images/TextKosti.png \
    Images/TextRememberNumber.png \
    Images/TextRuletka.png \
    Images/Vlast.png \
    Images/admin_page_back.png \
    Images/dice1.png \
    Images/dice2.png \
    Images/dice3.png \
    Images/dice4.png \
    Images/dice5.png \
    Images/dice6.png \
    Images/icon.png \
    Images/personal_page_back.png
