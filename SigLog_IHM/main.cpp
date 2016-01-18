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
#include  "SnmpCommands.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    /*
     * Initialize the SNMP library
     */

   init_snmp("SigLog_DataCenter");

   qmlRegisterType<MibTreeModel>("myCLibs", 1, 0, "MibTreeModel" );
   qmlRegisterType<Storage>("myCLibs", 1, 0, "Storage" );
   qmlRegisterType<FileSystemModel>("myCLibs", 1, 0, "FileSystemModel" );
   qmlRegisterType<ImageProviderWrapper>("myCLibs", 1, 0, "ImageProviderWrapper" );
   qmlRegisterType<QmlLogger>("myCLibs", 1, 0, "Logger" );
   qmlRegisterType<SnmpCommands>("myCLibs", 1, 0, "SnmpCommands" );

   QQmlApplicationEngine engine;

   FileSystemModel fsModelLocal;
   FileSystemModel fsModelRemote;
   ImageProvider imageProvider;

   QmlLogger logger;
   SnmpCommands commands;

   fsModelLocal.setRootPath(":/");
   fsModelRemote.setRootPath(":/");

   ImageProviderWrapper ipWrapper(&imageProvider);


   engine.rootContext()->setContextProperty("fsModelLocal", &fsModelLocal);
   engine.rootContext()->setContextProperty("fsModelRemote", &fsModelRemote);
   engine.rootContext()->setContextProperty("ipWrapper", &ipWrapper);
   engine.rootContext()->setContextProperty("logger", &logger);
   engine.rootContext()->setContextProperty("commands", &commands);

   engine.addImageProvider("provider",&imageProvider);

   engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
   return app.exec();
}
