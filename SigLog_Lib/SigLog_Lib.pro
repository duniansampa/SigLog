#-------------------------------------------------
#
# Project created by QtCreator 2015-11-07T19:10:24
#
#-------------------------------------------------

QT       -= gui

TARGET = SigLog_Lib
TEMPLATE = lib
CONFIG += staticlib

SOURCES += SigLog_Lib.cpp \
    MibManager.cpp

HEADERS += SigLog_Lib.h \
    MibManager.h \
    Includes.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
