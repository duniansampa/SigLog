/*
 * mibincl.h
 */

#include <stdio.h>
#include <sys/types.h>

#if HAVE_STDLIB_H
#include <stdlib.h>
#endif
#if HAVE_MALLOC_H
#include <malloc.h>
#endif
#if TIME_WITH_SYS_TIME
# include <sys/time.h>
# include <time.h>
#else
# if HAVE_SYS_TIME_H
#  include <sys/time.h>
# else
#  include <time.h>
# endif
#endif

#include <siglog/agent/mib_module_config.h>

#include <siglog/library/asn1.h>
#include <siglog/library/snmp_api.h>
#include <siglog/library/snmp_impl.h>
#include <siglog/library/snmp_client.h>

#include <siglog/agent/snmp_vars.h>
#include <siglog/agent/agent_read_config.h>
#include <siglog/agent/agent_handler.h>
#include <siglog/agent/agent_registry.h>
#include <siglog/agent/var_struct.h>

#include <siglog/library/snmp.h>
#include <siglog/library/mib.h>
#include <siglog/library/snmp_debug.h>
#include <siglog/library/snmp_logging.h>
#include <siglog/library/snmp_alarm.h>
#include <siglog/library/read_config.h>
#include <siglog/library/tools.h>
#include <siglog/agent/agent_trap.h>
#include <siglog/library/callback.h>
#define u_char unsigned char
#define u_short unsigned short
