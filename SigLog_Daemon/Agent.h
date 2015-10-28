#ifndef AGENT_H
#define AGENT_H



#include "../SDK/Base_Lib.h"

#include "SubAgent.h"
#include "AgentParameters.h"
#include "MibManager.h"

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-features.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include <net-snmp/agent/watcher.h>
#include <net-snmp/agent/instance.h>
#include <net-snmp/agent/scalar.h>
#include <signal.h>



extern "C" {
  void init_vacm_vars();
  void init_usmUser();
}


class Agent : public Thread
{

private:
    Barrier * _MainBarrier;
    Barrier * _SynchronizedBarrier;
    AgentParameters * _AgentParameters;
    SubAgent * _SubAgent;
    MibManager * _MibManager;
    static int _Keep_Running;
    static char *_AppName;


protected:
    void run();
public:
    Agent(Barrier * mainBarrier);
    virtual ~Agent();

    void initAgent();
    void executeAgent();
    void closeAgent();

    static RETSIGTYPE stopServer(int a);
};


#endif // AGENT_H
