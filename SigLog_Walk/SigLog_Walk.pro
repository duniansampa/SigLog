QT += core
QT -= gui

CONFIG += c++11

TARGET = siglogWalk
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

LIBS += -lsiglog

unix {
    QMAKE_CFLAGS += -fno-strict-aliasing -g -O2
}


SOURCES += main.cpp

HEADERS +=
