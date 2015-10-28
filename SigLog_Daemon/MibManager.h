#ifndef MIB_MANAGER_H
#define MIB_MANAGER_H

#include "../SDK/Base_Lib.h"

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-features.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/mib_api.h>

#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QDebug>

class MibManager
{
public:
    MibManager();
    void dfs(struct tree * mytree, QString tab, int prof);
    void print();
private:
    QFile _File;
    QTextStream _Out;
};

#endif // MIB_MANAGER_H
