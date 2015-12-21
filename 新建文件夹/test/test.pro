#-------------------------------------------------
#
# Project created by QtCreator 2015-12-04T16:34:30
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    configdialog.cpp \
    worker.cpp

HEADERS  += mainwindow.h \
    configdialog.h \
    worker.h

FORMS    += mainwindow.ui \
    configdialog.ui

DISTFILES += \
    test.pro.user \
    mypic.ico \
    res.rc
RC_FILE =

RESOURCES +=
RC_ICONS = mypic.ico
RC_FILE = res.rc
