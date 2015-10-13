#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtGui>
#include <QtQml>

#include <QFileSystemModel>

#include "TreeModel.h"
#include  "Storage.h"
#include "FileSystemModel.h"
#include "ImageProviderWrapper.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);


   qmlRegisterType<MyTreeModel>("myCLibs", 1, 0, "TreeModel" );
   qmlRegisterType<Storage>("myCLibs", 1, 0, "Storage" );
   qmlRegisterType<FileSystemModel>("myCLibs", 1, 0, "FileSystemModel" );
   qmlRegisterType<ImageProviderWrapper>("myCLibs", 1, 0, "ImageProviderWrapper" );


   QQmlApplicationEngine engine;

   FileSystemModel fsModelLocal;
   FileSystemModel fsModelRemote;
   ImageProvider imageProvider;

   fsModelLocal.setRootPath(":/");
   fsModelRemote.setRootPath(":/");

   ImageProviderWrapper ipWrapper(&imageProvider);


   engine.rootContext()->setContextProperty("fsModelLocal", &fsModelLocal);
   engine.rootContext()->setContextProperty("fsModelRemote", &fsModelRemote);
   engine.rootContext()->setContextProperty("ipWrapper", &ipWrapper);

   engine.addImageProvider("provider",&imageProvider);

   engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
   return app.exec();
}
