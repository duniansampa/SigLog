TEMPLATE = app

QT += qml quick widgets xml

CONFIG += C++11 console
CONFIG += qml_debug

LIBS += -lnetsnmp -lnetsnmpagent  -lnetsnmpmibs -lnetsnmphelpers

SOURCES += main.cpp \
    Storage.cpp \
    FileSystemModel.cpp \
    ImageProvider.cpp \
    MibTreeModel.cpp \
    QmlLogger.cpp

RESOURCES += \
    qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

DISTFILES +=

HEADERS += \
    Storage.h \
    FileSystemModel.h \
    ImageProvider.h \
    ImageProviderWrapper.h \
    MibTreeModel.h \
    QmlLogger.h


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
