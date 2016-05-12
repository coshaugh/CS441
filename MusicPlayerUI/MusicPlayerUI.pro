#-------------------------------------------------
#
# Project created by QtCreator 2016-03-28T10:52:53
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MusicPlayerUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindowui.cpp \
    playerui.cpp

HEADERS  += mainwindowui.h \
    playerui.h

FORMS    += mainwindowui.ui \
    playerui.ui
