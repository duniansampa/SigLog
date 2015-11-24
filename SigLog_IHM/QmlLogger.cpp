#include "QmlLogger.h"

QmlLogger::QmlLogger(QObject *parent) : QObject(parent)
{

}

// Your Constructor

// Implementation of log method callable from Qml source
void QmlLogger::log( const QString& iDataToLog)
{
    cout<< iDataToLog.toStdString() << endl;
}
