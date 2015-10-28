QT     += core
TEMPLATE = app
CONFIG += console

SOURCES += \
    Main.cpp \
    Agent.cpp \
    AgentParameters.cpp \
    SubAgent.cpp \
    ../SDK/Threads/Barrier.cpp \
    ../SDK/Threads/ConditionVariable.cpp \
    ../SDK/Threads/Mutex.cpp \
    ../SDK/Threads/Semaphore.cpp \
    ../SDK/Threads/SynchronizationService.cpp \
    ../SDK/Threads/Synchronized.cpp \
    ../SDK/Threads/Thread.cpp \
    ../SDK/Base/Object.cpp \
    ../SDK/Base/String.cpp \
    MibManager.cpp

HEADERS += \
    Agent.h \
    AgentParameters.h \
    SubAgent.h \
    ../SDK/Base_Lib.h \
    ../SDK/BaseIncludes.h \
    ../SDK/Threads/Barrier.h \
    ../SDK/Threads/ConditionVariable.h \
    ../SDK/Threads/Mutex.h \
    ../SDK/Threads/Semaphore.h \
    ../SDK/Threads/SynchronizationService.h \
    ../SDK/Threads/Synchronized.h \
    ../SDK/Threads/Thread.h \
    ../SDK/Base/Base.h \
    ../SDK/Base/Object.h \
    ../SDK/Base/String.h \
    MibManager.h

QMAKE_CXXFLAGS += -std=c++0x -pthread
LIBS += -pthread -lnetsnmp -lnetsnmpagent  -lnetsnmpmibs -lnetsnmphelpers

TARGET = SigLog_Daemon
target.path += /home/root
target.files += SigLog_Daemon
INSTALLS += target
