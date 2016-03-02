#ifndef OPTIONS_H
#define OPTIONS_H

#include "includes.h"

#include <QObject>
#include <QString>


class Options : public QObject
{
    Q_OBJECT

private:
    QString m_appName;
    bool m_dontFork = 0;
    bool m_doHelp;
    bool m_logSet;
    char * m_pidFile;
    int m_agentMode;
    int m_dumpPacket;


public:
    explicit Options(QObject *parent = 0);

    void usage(char *prog);
    void version(void);
    void process(int argc, char *argv[]);

    QString appName();
    void appName(QString & name);
    bool dontFork();
    void dontFork(bool dontfork);
    bool doHelp();
    void doHelp(bool dohelp);
    bool logSet();
    void logSet(bool logset);
    int  agentMode();
    void agentMode(int agentmode);
    char * pidFile();
    void pidFile(char * pidfile);

signals:

public slots:
};

#endif // OPTIONS_H
