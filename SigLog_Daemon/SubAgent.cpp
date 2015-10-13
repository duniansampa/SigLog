
#include "SubAgent.h"

#define printVecOID(vec, size) for(int i = 0; i <size; i++ ) cout<<vec[i]<<"."; cout<<endl;

SubAgent::SubAgent(): eldcomNumber(ASN_INTEGER,    1),
                                  eldcomName  (ASN_OCTET_STR,  50),
                                  eldcomObjID (ASN_OBJECT_ID,  5),
                                  eldcomIP    (ASN_IPADDRESS,  4),
                                  eldcomFloat (ASN_FLOAT,      1),
                                  eldcomDouble(ASN_DOUBLE,     1)
{

    eldcomNumber.setStringOid(".1.3.6.1.4.1.8072.2.4.1.1.1.100");
    eldcomNumber.setContent("240");

    eldcomName.setStringOid(".1.3.6.1.4.1.8072.2.4.1.1.1.101");
    eldcomName.setContent("Software de SMC");



    eldcomIP.setStringOid(".1.3.6.1.4.1.8072.2.4.1.1.1.102");
    eldcomIP.setContent("10.255.255.10",". ");

    eldcomObjID.setStringOid(".1.3.6.1.4.1.8072.2.4.1.1.1.103");
    eldcomObjID.setContent(".1.2.3.4.8");

    eldcomFloat.setStringOid(".1.3.6.1.4.1.8072.2.4.1.1.1.104");
    eldcomFloat.setContent("20");

    eldcomDouble.setStringOid(".1.3.6.1.4.1.8072.2.4.1.1.1.105");
    eldcomDouble.setContent("50");



}

void registerDataSet();

inline void SubAgent::registerObject(char * name, AgentSubagentObject * agentSubagentObject){

    netsnmp_handler_registration *reginfo;
    netsnmp_watcher_info  * watcher_info = new netsnmp_watcher_info() ;
    void * content;
    size_t length;
    size_t size;

    switch( agentSubagentObject->getType()){

    case ASN_INTEGER:
        content  =  agentSubagentObject->_Content.integer;
        size = agentSubagentObject->getSizeContent() * sizeof (long);
        length  = size;
        break;

    case ASN_OBJECT_ID:
        content  =  agentSubagentObject->_Content.objid;
        size = agentSubagentObject->getSizeContent() * sizeof (oid);
        length = size;
        break;

    case ASN_FLOAT:
        content  =  agentSubagentObject->_Content.floatVal;
        size = agentSubagentObject->getSizeContent() * sizeof (float);
        length = size;
        break;

    case ASN_DOUBLE:
        content  =  agentSubagentObject->_Content.doubleVal;
        size = agentSubagentObject->getSizeContent() * sizeof (double);
        length = size;

    case ASN_IPADDRESS:
        content  =  agentSubagentObject->_Content.string;
        length  =  agentSubagentObject->getSizeContent();
        size = length;
        break;

    case ASN_OCTET_STR:
        content  =  agentSubagentObject->_Content.string;
        length  = strlen((char *)agentSubagentObject->_Content.string);
        size = agentSubagentObject->getSizeContent();
        break;
    }

    reginfo = netsnmp_create_handler_registration(name, agentSubagentObject->getHandler(),
                                                  agentSubagentObject->getPtrVecOid(),
                                                  agentSubagentObject->getSizeVecOid(),
                                                  HANDLER_CAN_RWRITE);

    netsnmp_init_watcher_info6(watcher_info, content, length, agentSubagentObject->getType(),
                               WATCHER_MAX_SIZE,size, NULL);

    netsnmp_register_watched_instance(reginfo, watcher_info);

}


SubAgent::~SubAgent(){


}

void SubAgent::initObjects(){

    this->registerObject(CLASS_NAME(eldcomNumber), &eldcomNumber);
    this->registerObject(CLASS_NAME(eldcomName), &eldcomName);
    //this->registerObject(CLASS_NAME(eldcomObjID), eldcomObjID);
    this->registerObject(CLASS_NAME(eldcomIP), &eldcomIP);
    //this->registerObject(CLASS_NAME(eldcomFloat), &eldcomFloat);
    //this->registerObject(CLASS_NAME(eldcomDouble), &eldcomDouble);
}


//# the generic traps
//traphandle SNMPv2-MIB::coldStart    /home/nba/bin/traps cold  Oid: .1.3.6.1.6.3.1.1.5.1
//traphandle SNMPv2-MIB::warmStart    /home/nba/bin/traps warm
//traphandle IF-MIB::linkDown         /home/nba/bin/traps down
//traphandle IF-MIB::linkUp           /home/nba/bin/traps up
//traphandle SNMPv2-MIB::authenticationFailure /home/nba/bin/traps auth
//# this one is deprecated
//traphandle .1.3.6.1.6.3.1.1.5.6     /home/nba/bin/traps egp-neighbor-loss


void SubAgent::sendNotification(AgentSubagentObject * notificationTrap, AgentSubagentObject * agentSubagentObject) {



    cout<<"Sending trap..."<<endl;

    netsnmp_variable_list *notification_vars = NULL;

    snmp_varlist_add_variable(&notification_vars,

                               // the snmpTrapOID.0 variable

                              notificationTrap->getPtrVecOid(), notificationTrap->getSizeVecOid(),

                               // value type is an OID

                              ASN_OBJECT_ID,

                              // value contents is our notification OID

                              (u_char *)notificationTrap->_Content.objid,

                               // size in bytes = oid length * sizeof(oid)

                              notificationTrap->getSizeContent() * sizeof(oid));


    // add in the additional objects defined as part of the trap

    snmp_varlist_add_variable(&notification_vars,
                              agentSubagentObject->getPtrVecOid(),
                              agentSubagentObject->getSizeVecOid(),
                              agentSubagentObject->getType(),
                              (u_char *)agentSubagentObject->_Content.string,
                              agentSubagentObject->getSizeContent());


    send_v2trap(notification_vars);

    snmp_free_varbind(notification_vars);
}
