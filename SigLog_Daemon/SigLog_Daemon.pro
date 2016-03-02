QT += core
QT -= gui

CONFIG += c++11

TARGET = siglogDaemon
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

LIBS += -lsiglog -lsiglogagent -lsiglogmib

unix {
    QMAKE_CFLAGS += -fno-strict-aliasing -g -O2
}

unix {
    target.path += /home/root
    INSTALLS += target
}

SOURCES += \
    options.cpp \
    signals.cpp \
    siglogd.cpp \
    main.cpp

HEADERS += \
    options.h \
    signals.h \
    siglogd.h \
    includes.h

DISTFILES +=
