#ifndef SIGNALS_H
#define SIGNALS_H

#include "includes.h"

#include <QObject>

class Signals : public QObject
{
    Q_OBJECT
public:

    static int     RECONFIG;


    explicit Signals(QObject *parent = 0);

    void registerOne(int sig, void (* handle)(int) );
    void registerAll();

    static void shutDown(int a);
    static void reconfig(int a);
    static void dump(int a);

    static void catchRandomSignal(int a);



signals:

public slots:
};

#endif // SIGNALS_H
