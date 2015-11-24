#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtGui>
#include <QtQml>

#include <QFileSystemModel>

#include "MibTreeModel.h"
#include  "Storage.h"
#include "FileSystemModel.h"
#include "ImageProviderWrapper.h"
#include  "QmlLogger.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);


   qmlRegisterType<MibTreeModel>("myCLibs", 1, 0, "MibTreeModel" );
   qmlRegisterType<Storage>("myCLibs", 1, 0, "Storage" );
   qmlRegisterType<FileSystemModel>("myCLibs", 1, 0, "FileSystemModel" );
   qmlRegisterType<ImageProviderWrapper>("myCLibs", 1, 0, "ImageProviderWrapper" );
   qmlRegisterType<QmlLogger>("myCLibs", 1, 0, "Logger" );




   QQmlApplicationEngine engine;

   FileSystemModel fsModelLocal;
   FileSystemModel fsModelRemote;
   ImageProvider imageProvider;

   QmlLogger logger;

   fsModelLocal.setRootPath(":/");
   fsModelRemote.setRootPath(":/");

   ImageProviderWrapper ipWrapper(&imageProvider);


   engine.rootContext()->setContextProperty("fsModelLocal", &fsModelLocal);
   engine.rootContext()->setContextProperty("fsModelRemote", &fsModelRemote);
   engine.rootContext()->setContextProperty("ipWrapper", &ipWrapper);
   engine.rootContext()->setContextProperty("logger", &logger);

   engine.addImageProvider("provider",&imageProvider);

   engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
   return app.exec();
}
