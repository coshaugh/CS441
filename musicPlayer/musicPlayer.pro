#-------------------------------------------------
#
# Project created by QtCreator 2016-04-19T10:12:31
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = musicPlayer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    user.cpp \
    hostuser.cpp \
    clientuser.cpp \
    server.cpp \
    client.cpp

HEADERS  += mainwindow.h \
    user.h \
    hostuser.h \
    clientuser.h \
    server.h \
    client.h

FORMS    += mainwindow.ui
