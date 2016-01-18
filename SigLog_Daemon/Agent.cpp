

#include "Agent.h"

int Agent::_Keep_Running = 1;

Agent::Agent()
{

    this->_SubAgent 	   =  new SubAgent();
    this->_AgentParameters =  new AgentParameters("/tmp/SystemConfig.xml");
    this->_MibManager = new MibManager("/usr/share/snmp/mibs/NET-SNMP-EXAMPLES-MIB.txt");

}


Agent::~Agent(){


}

void Agent::run(){

    cout << endl<<endl<< "Agent is executing!" << endl << endl;


    if (this->_AgentParameters->LoadAgentParameters() == AgentParameters::SUCCESS){
        cout<<"Agent parameters loaded successfully."<<endl;
    }else{
        cout<<"Agent parameters not loaded successfully."<<endl;
        return;
    }

    cout<<"Initializing..."<<endl;

    this->initAgent();

    cout<<"Running..."<<endl;
    this->executeAgent();

    cout<<"Closing..."<<endl;
    this->closeAgent();

    cout<<"Closed." << endl;

    exit(1);
}

void Agent::initAgent(){

     int ret;
     string appName = this->_AgentParameters->getSnmpdConfig();

    // print log errors to syslog or stderr
    if (this->_AgentParameters->getPrintLogERROR() == AgentParameters::_SYS_LOG_)
      snmp_enable_calllog();
    else
      snmp_enable_stderrlog();

    //we're an agentx subagent?
    if (this->_AgentParameters->getOperationMode() == AgentParameters::_SUB_AGENT_) {
      // make us a agentx client.
      netsnmp_ds_set_boolean(NETSNMP_DS_APPLICATION_ID, NETSNMP_DS_AGENT_ROLE, AgentParameters::_SUB_AGENT_);
    }else{
        netsnmp_ds_set_boolean(NETSNMP_DS_APPLICATION_ID, NETSNMP_DS_AGENT_ROLE, AgentParameters::_MASTER_AGENT_);
    }

   //netsnmp_ds_set_boolean(NETSNMP_DS_APPLICATION_ID, NETSNMP_DS_AGENT_NO_ROOT_ACCESS, 1);
   // netsnmp_ds_set_string(NETSNMP_DS_APPLICATION_ID, NETSNMP_DS_AGENT_X_SOCKET, "tcp:localhost:705");


    // initialize tcpip, if necessary
    SOCK_STARTUP;
    if (init_agent(appName.c_str()) != 0) {
        snmp_log(LOG_ERR, "Agent initialization failed\n");
        exit(1);
    }

    init_mib_modules();

    /*
     * start library
     */

    //mib code:
    this->_SubAgent->initObjects();


    init_snmp(appName.c_str());

    if ((ret = init_master_agent()) != 0) {
        /*
         * Some error openin    this->_MibManager->print();g one of the specified agent transports.
         */
        snmp_log(LOG_ERR, "Server Exiting with code 1\n");
        exit(1);
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
    string appName = this->_AgentParameters->getSnmpdConfig();
    snmp_shutdown(appName.c_str());
    SOCK_CLEANUP;

}

RETSIGTYPE Agent::stopServer(int a){
    Agent::_Keep_Running = 0;
}

