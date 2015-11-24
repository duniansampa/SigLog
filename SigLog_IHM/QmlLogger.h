#ifndef QMLLOGGER_H
#define QMLLOGGER_H

#include <QObject>

class QmlLogger : public QObject
{
    Q_OBJECT
public:
    explicit QmlLogger(QObject *parent = 0);

signals:

public slots:
};

#endif // QMLLOGGER_H
