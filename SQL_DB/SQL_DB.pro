#-------------------------------------------------
#
# Project created by QtCreator 2014-12-11T20:19:57
#
#-------------------------------------------------

QT       += core gui #here we add sql so that it can recognize

QT += sql



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SQL_DB
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    databasehelper.cpp

HEADERS  += mainwindow.h \
    databasehelper.h

FORMS    += mainwindow.ui
