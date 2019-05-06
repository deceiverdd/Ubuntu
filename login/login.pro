#-------------------------------------------------
#
# Project created by QtCreator 2018-10-18T10:46:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = login
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    logindialog.cpp \
    startupmenu.cpp \
    painter.cpp \
    gvframework.cpp \
    myitem.cpp \
    rectitem.cpp

HEADERS += \
        mainwindow.h \
    logindialog.h \
    startupmenu.h \
    painter.h \
    gvframework.h \
    myitem.h \
    rectitem.h

FORMS += \
        mainwindow.ui \
    logindialog.ui \
    startupmenu.ui \
    painter.ui \
    gvframework.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    myicon.qrc

msvc:QMAKE_CXXFLAGS += -execution-charset:utf-8
