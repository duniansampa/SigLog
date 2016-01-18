QT     += core
TEMPLATE = app
CONFIG += console

SOURCES += \
    Main.cpp \
    Agent.cpp \
    AgentParameters.cpp \
    SubAgent.cpp \

HEADERS += \
    Agent.h \
    AgentParameters.h \
    SubAgent.h

QMAKE_CXXFLAGS += -std=c++0x
LIBS += -lnetsnmp -lnetsnmpagent  -lnetsnmpmibs -lnetsnmphelpers

TARGET = SigLog_Daemon

unix {
    target.path += /home/root
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-SigLog_Lib-Desktop-Debug/release/ -lSigLog_Lib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-SigLog_Lib-Desktop-Debug/debug/ -lSigLog_Lib
else:unix: LIBS += -L$$PWD/../build-SigLog_Lib-Desktop-Debug/ -lSigLog_Lib

INCLUDEPATH += $$PWD/../SigLog_Lib
DEPENDPATH += $$PWD/../SigLog_Lib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-SigLog_Lib-Desktop-Debug/release/libSigLog_Lib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-SigLog_Lib-Desktop-Debug/debug/libSigLog_Lib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-SigLog_Lib-Desktop-Debug/release/SigLog_Lib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-SigLog_Lib-Desktop-Debug/debug/SigLog_Lib.lib
else:unix: PRE_TARGETDEPS += $$PWD/../build-SigLog_Lib-Desktop-Debug/libSigLog_Lib.a
