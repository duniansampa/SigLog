QT += core
QT -= gui

CONFIG += c++11

TARGET = siglogDaemon
CONFIG += console
CONFIG -= app_bundle
CONFIG += debug

TEMPLATE = app

LIBS += -lsiglog -lsiglogagent -lsiglogmib
#QT_NO_DEBUG_OUTPUT, QT_NO_WARNING_OUTPUT, or QT_NO_DEBUG_STREAM

unix {
    QMAKE_CFLAGS += -fno-strict-aliasing -g -O2
}

unix {
    target.path += /home/root
    INSTALLS += target
}

SOURCES += \
#    options.cpp \
#    signals.cpp \
#    siglogd.cpp \
#    main.cpp \
    snmpd.cpp

HEADERS += \
#    options.h \
#    signals.h \
#    siglogd.h \
#    includes.h \
    snmpd.h

DISTFILES +=
