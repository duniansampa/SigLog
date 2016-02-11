QT += core
QT -= gui

CONFIG += c++11

TARGET = siglogTrapDaemon
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

LIBS += -lsiglog -lsiglogagent -lsiglogmib


unix {
    QMAKE_CFLAGS += -fno-strict-aliasing -g -O2
}

unix {
#    VERSION  = 1.0.0    # major.minor.patch
    INCLUDEPATH += "$$PWD/../SigLog_MibLib"
    QMAKE_CFLAGS += -fno-strict-aliasing -g -O2
}

SOURCES += \
    snmptrapd_handlers.c \
    snmptrapd_log.c \
    snmptrapd_auth.c \
    snmptrapd_sql.c \
    main.c

