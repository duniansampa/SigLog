/*
 * swinst_null.c:
 *     hrSWInstalledTable data access:
 *     dummy interface for non-supported systems
 */
#include <siglog/net-snmp-config.h>

#include <stdio.h>
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#include <siglog/net-snmp-includes.h>
#include <siglog/agent/net-snmp-agent-includes.h>
#include <siglog/library/container.h>
#include <siglog/library/snmp_debug.h>
#include <siglog/data_access/swinst.h>

/* ---------------------------------------------------------------------
 */
void
netsnmp_swinst_arch_init(void)
{
    /* Nothing to do */
    return;
}

void
netsnmp_swinst_arch_shutdown(void)
{
    /* Nothing to do */
    return;
}

/* ---------------------------------------------------------------------
 */
int
netsnmp_swinst_arch_load( netsnmp_container *container, u_int flags)
{
    /* Nothing to do */
    DEBUGMSGTL(("swinst:load:arch"," loaded %" NETSNMP_PRIz "d entries\n",
                CONTAINER_SIZE(container)));

    return 0;
}
