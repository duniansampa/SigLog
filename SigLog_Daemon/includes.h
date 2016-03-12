#ifndef INCLUDES_H
#define INCLUDES_H


#include <siglog/net-snmp-config.h>
#include <siglog/net-snmp-features.h>
#include <siglog/types.h>

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "siglogd.h"
#include "includes.h"
#include "options.h"
#include "signals.h"


netsnmp_feature_want(logging_file)
netsnmp_feature_want(logging_stdio)
netsnmp_feature_want(logging_syslog)

/*
 * Globals.
 */
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
# include <sys/time.h>
# include <time.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/file.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/param.h>
#include <limits.h>
#include <pwd.h>
#include <grp.h>

#ifndef PATH_MAXSnmpdReconfig
# ifdef _POSIX_PATH_MAX
#  define PATH_MAX _POSIX_PATH_MAX
# else
#  define PATH_MAX 255
# endif
#endif



#include <siglog/net-snmp-includes.h>
#include <siglog/agent/net-snmp-agent-includes.h>

#include <siglog/library/fd_event_manager.h>
#include <siglog/library/large_fd_set.h>

#include "m2m.h"
#include <siglog/agent/agent_module_config.h>
#include <siglog/agent/mib_module_config.h>

#include <siglog/agent/mib_modules.h>

#include <siglog/agent/agent_trap.h>

#include <siglog/agent/table.h>
#include <siglog/agent/table_iterator.h>

#define MASTER_AGENT 0
#define SUB_AGENT    1
#define TIMETICK     500000L

extern int      netsnmp_running;
extern int      snmp_dump_packet;




#endif // INCLUDES_H
