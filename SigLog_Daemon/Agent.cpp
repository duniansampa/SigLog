

#include "Agent.h"

int Agent::_Keep_Running = 1;

Agent::Agent(Barrier * mainBarrier)
{
    Super(this);
    this->setName("Agent");
    // SHOW(sched_get_priority_min(SCHED_RR));
    //this->setPriority(Thread::PRIORITY_MAX);
    //this->setStackSize(Thread::STACK_SIZE_DEFAULT);
    //this->setSchedulingPolicy(Thread::RROBIN_ALG);

    this->_MainBarrier = mainBarrier;

    this->_SubAgent 	   =  new SubAgent() ;
    this->_AgentParameters =  new AgentParameters("/tmp/SystemConfig.xml");
}

Agent::~Agent(){

}

void Agent::run(){

    cout << endl<<endl<< "Agent is executing!" << endl << endl;


    if (this->_AgentParameters->LoadAgentParameters() == AgentParameters::SUCCESS){
        cout<<"Agent parameters loaded successfully."<<endl;
    }else{
        cout<<"Agent parameters not loaded successfully."<<endl;
        this->_MainBarrier->wait();
        return;
    }

    this->_SynchronizedBarrier   =  new Barrier(1);


    cout<<"Initializing..."<<endl;

    this->initAgent();

    cout<<"Running..."<<endl;
    this->executeAgent();

    cout<<"Closing..."<<endl;
    this->closeAgent();

    this->_MainBarrier->wait();

}

void Agent::initAgent(){


    // print log errors to syslog or stderr
    if (this->_AgentParameters->getPrintLogERROR() == AgentParameters::_SYS_LOG_)
      snmp_enable_calllog();
    else
      snmp_enable_stderrlog();

    //we're an agentx subagent?
    if (this->_AgentParameters->getOperationMode() == AgentParameters::_SUB_AGENT_) {
      // make us a agentx client.
      netsnmp_ds_set_boolean(NETSNMP_DS_APPLICATION_ID, NETSNMP_DS_AGENT_ROLE, 1);
    }


    netsnmp_ds_set_string(NETSNMP_DS_APPLICATION_ID, NETSNMP_DS_AGENT_X_SOCKET, "tcp:localhost:705");

    // initialize tcpip, if necessary
    SOCK_STARTUP;

    // initialize the agent library
    init_agent("");


    //mib code:
    this->_SubAgent->initObjects();


    // initialize vacm/usm access control
    if (this->_AgentParameters->getOperationMode() == AgentParameters::_MASTER_AGENT_) {
        init_vacm_vars();
        init_usmUser();
    }

    // Agent will be used to read AgentConfig.conf files.
     init_snmp("");

    // If we're going to be a snmp master agent, initial the ports
    if (this->_AgentParameters->getOperationMode() == AgentParameters::_MASTER_AGENT_){
      //open the port to listen on (defaults to udp:161)
      init_master_agent();
    }

    // In case we recevie a request to stop (kill -TERM or kill -INT)
    signal(SIGTERM, Agent::stopServer);
    signal(SIGINT,  Agent::stopServer);

    snmp_log(LOG_INFO,"Agent is up and running.\n");

}

void Agent::executeAgent(){

     //your main loop here...

    while(Agent::_Keep_Running) {
      // if you use select(), see snmp_select_info() in snmp_api(3)
      //     --- OR ---
      //0 == don't block
      agent_check_and_process(1);
    }
}

void Agent::closeAgent(){

    //at shutdown time
    snmp_shutdown("Agent");
    SOCK_CLEANUP;

}

RETSIGTYPE Agent::stopServer(int a){
    Agent::_Keep_Running = 0;
}

