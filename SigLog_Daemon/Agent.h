#ifndef AGENT_H
#define AGENT_H

#include <Includes.h>

#include "SubAgent.h"
#include "AgentParameters.h"
#include <MibManager.h>
#include <SigLog_Lib.h>

#include <QObject>
#include <QThread>

class Agent :  public QThread
{

private:
    AgentParameters * _AgentParameters;
    SubAgent * _SubAgent;
    MibManager * _MibManager;
    static int _Keep_Running;

protected:
    void run();
public:
    Agent();
    ~Agent();

    void initAgent();
    void executeAgent();
    void closeAgent();

    static RETSIGTYPE stopServer(int a);

public slots:

signals:
};


#endif // AGENT_H
