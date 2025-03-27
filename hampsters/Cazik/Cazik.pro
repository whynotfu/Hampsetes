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
    kliker.ui \
    kosti.ui \
    personal_page.ui \
    ruletka.ui

DISTFILES += \
    Images/Casic.png \
    Images/FonCasinoReg.png \
    Images/icon.png
