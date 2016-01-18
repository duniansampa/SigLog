QT += core
QT -= gui



TARGET = index.cgi
#target.path = /var/www/cgi-bin/
#INSTALLS += target
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

LIBS += -lcgicc

SOURCES += main.cpp \
    getcgi_siglog.cpp \
    envcgi_siglog.cpp



