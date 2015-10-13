MAKEFILE_GENERATOR = UNIX
TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += \
    Main.cpp \

HEADERS += \

QMAKE_CXXFLAGS += -std=c++0x -pthread
#MAKE_CXXFLAGS += -std=c++0x -pthread
#LIBS += -pthread
LIBS +=
# -pthread -lnetsnmp -lnetsnmpagent  -lnetsnmpmibs -lnetsnmphelpers

TARGET = SigLog_Daemon
target.path += /home/root
target.files += SigLog_Daemon
INSTALLS += target
