#ifndef SNMPCOMMANDS_H
#define SNMPCOMMANDS_H

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <string.h>

#include <QObject>

class SnmpCommands : public QObject
{
    Q_OBJECT
public:
   explicit SnmpCommands(QObject *parent = 0);

   Q_INVOKABLE int get();

private:
    const char *our_v3_passphrase;

    netsnmp_session session, *ss;
    netsnmp_pdu *pdu;
    netsnmp_pdu *response;

    oid anOID[MAX_OID_LEN];

    size_t anOID_len;

    netsnmp_variable_list * vars;
};

#endif // SNMPCOMMANDS_H
