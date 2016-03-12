#include <siglog/net-snmp-config.h>
#include <siglog/net-snmp-includes.h>
#include <siglog/agent/net-snmp-agent-includes.h>
#include <siglog/agent/hardware/fsys.h>

int
_fsys_remote( char *device, int type )
{
    return 0;
}

int
_fsys_type( char *typename )
{
    return NETSNMP_FS_TYPE_UNKNOWN;
}

void
netsnmp_fsys_arch_init( void )
{ }

void
netsnmp_fsys_arch_load( void )
{ }
