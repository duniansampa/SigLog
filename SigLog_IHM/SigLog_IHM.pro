TEMPLATE = app

QT += qml quick widgets xml

CONFIG += C++11

SOURCES += main.cpp \
    Storage.cpp \
    TreeModel.cpp \
    FileSystemModel.cpp \
    ImageProvider.cpp

RESOURCES += \
    qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

DISTFILES +=

HEADERS += \
    Storage.h \
    TreeModel.h \
    FileSystemModel.h \
    ImageProvider.h \
    ImageProviderWrapper.h
