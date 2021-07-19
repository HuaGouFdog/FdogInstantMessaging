#-------------------------------------------------
#
# Project created by QtCreator 2021-03-20T22:04:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Fdog
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    login.cpp \
    usersql.cpp \
    query.cpp \
    chat.cpp \
    settingcolor.cpp \
    addfriend.cpp \
    globalobserver.cpp \
    verify.cpp \
    traywidget.cpp \
    agreefriend.cpp

HEADERS += \
        mainwindow.h \
    login.h \
    usersql.h \
    query.h \
    chat.h \
    settingcolor.h \
    addfriend.h \
    globalobserver.h \
    verify.h \
    traywidget.h \
    agreefriend.h

FORMS += \
        mainwindow.ui \
    login.ui \
    query.ui \
    chat.ui \
    settingcolor.ui \
    addfriend.ui \
    verify.ui \
    traywidget.ui \
    agreefriend.ui

RESOURCES += \
    libres.qrc


QT +=sql

QT += network

CONFIG += resources_big

QMAKE_CXXFLAGS += /MP

