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


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-SigLog_Lib-Desktop_Qt_5_5_1_GCC_64bit-Release/release/ -lSigLog_Lib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-SigLog_Lib-Desktop_Qt_5_5_1_GCC_64bit-Release/debug/ -lSigLog_Lib
else:unix: LIBS += -L$$PWD/../build-SigLog_Lib-Desktop_Qt_5_5_1_GCC_64bit-Release/ -lSigLog_Lib

INCLUDEPATH += $$PWD/../build-SigLog_Lib-Desktop_Qt_5_5_1_GCC_64bit-Release
DEPENDPATH += $$PWD/../build-SigLog_Lib-Desktop_Qt_5_5_1_GCC_64bit-Release

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-SigLog_Lib-Desktop_Qt_5_5_1_GCC_64bit-Release/release/libSigLog_Lib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-SigLog_Lib-Desktop_Qt_5_5_1_GCC_64bit-Release/debug/libSigLog_Lib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-SigLog_Lib-Desktop_Qt_5_5_1_GCC_64bit-Release/release/SigLog_Lib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-SigLog_Lib-Desktop_Qt_5_5_1_GCC_64bit-Release/debug/SigLog_Lib.lib
else:unix: PRE_TARGETDEPS += $$PWD/../build-SigLog_Lib-Desktop_Qt_5_5_1_GCC_64bit-Release/libSigLog_Lib.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-SigLog_Lib-Desktop_Qt_5_5_1_GCC_64bit-Release/release/ -lSigLog_Lib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-SigLog_Lib-Desktop_Qt_5_5_1_GCC_64bit-Release/debug/ -lSigLog_Lib
else:unix: LIBS += -L$$PWD/../build-SigLog_Lib-Desktop_Qt_5_5_1_GCC_64bit-Release/ -lSigLog_Lib

INCLUDEPATH += $$PWD/../SigLog_Lib
DEPENDPATH += $$PWD/../SigLog_Lib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-SigLog_Lib-Desktop_Qt_5_5_1_GCC_64bit-Release/release/libSigLog_Lib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-SigLog_Lib-Desktop_Qt_5_5_1_GCC_64bit-Release/debug/libSigLog_Lib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-SigLog_Lib-Desktop_Qt_5_5_1_GCC_64bit-Release/release/SigLog_Lib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-SigLog_Lib-Desktop_Qt_5_5_1_GCC_64bit-Release/debug/SigLog_Lib.lib
else:unix: PRE_TARGETDEPS += $$PWD/../build-SigLog_Lib-Desktop_Qt_5_5_1_GCC_64bit-Release/libSigLog_Lib.a
