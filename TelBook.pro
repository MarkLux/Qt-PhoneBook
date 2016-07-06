#-------------------------------------------------
#
# Project created by QtCreator 2016-07-05T15:58:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TelBook
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    editdialog.cpp \
    confirmdialog.cpp \
    querydialog.cpp

HEADERS  += mainwindow.h \
    editdialog.h \
    confirmdialog.h \
    querydialog.h

FORMS    += mainwindow.ui \
    editdialog.ui \
    confirmdialog.ui \
    querydialog.ui
