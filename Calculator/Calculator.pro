QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calculator.cpp \
    credit_calculator.cpp \
    deposit_calculator.cpp \
    form_x.cpp \
    main.cpp \
    mainwindow.cpp \
    mybutton.cpp \
    s21_back_for_credit_calculator.c \
    s21_calcul.c

HEADERS += \
    calculator.h \
    credit_calculator.h \
    deposit_calculator.h \
    form_x.h \
    mainwindow.h \
    mybutton.h \
    s21_back_for_credit_calculator.h \
    s21_calcul.h

FORMS += \
    credit_calculator.ui \
    deposit_calculator.ui \
    form_x.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
