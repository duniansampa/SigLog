QT += core
QT -= gui

CONFIG += c++11

TARGET = index.cgi
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app


LIBS += -lcgicc

SOURCES += main.cpp \
    getcgi_siglog.cpp \
    envcgi_siglog.cpp



