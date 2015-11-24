#ifndef QMLLOGGER_H
#define QMLLOGGER_H

#include <QObject>

#include <Includes.h>


class QmlLogger : public QObject
{
    Q_OBJECT
public:
    explicit QmlLogger(QObject *parent = 0);

    Q_INVOKABLE void log(const QString& iDataToLog);

    enum Level
    {
        Error = 0,
        Warning,
        Info,
        Debug,
        Trace
    };
    Q_ENUMS(Level)

private:

};

#endif // QMLLOGGER_H
