#ifndef BASE_INCLUDES_H_
#define BASE_INCLUDES_H_

/*!
 * \brief     Sample application.
 * \details   This application is used to show some doxygen tips.
 * \author    Dunian Coutinho Sampa
 * \version   1.0a
 * \date      2014-2014
 * \pre       Have a Linux and C/C++ environment configured.
 * \bug       No bug.
 * \warning   N/A
 * \copyright MECTRON LTDA.
 */

//! \brief These are the default C++ includes.
#include <iostream>         // For collections
#include <stdio.h>          // printf
//#include <sys/neutrino.h>	// ConnectServerInfo, MsgSend
#include <iomanip>          // setfill, setw
#include <vector>           // For vector collection
#include <map>              // For Map collection
//#include <spawn.h>          // For spawn process
//#include <process.h>        // For getpid()
#include <sys/types.h>      // mkdir, rmdir
#include <sys/stat.h>       // mkdir
#include <unistd.h>         // rmdir
#include <errno.h>          // errno
#include <list>             // list
#include <dirent.h>         // DIR
#include <string>           // string
#include <fstream>          // fstream
#include <sstream>          // stringstream
//#include <sys/dispatch.h>   // Needed for IPC
#include <pthread.h>        //threads
#include <semaphore.h>      //semaphore
#include <sched.h>          //
#include <errno.h>          //errno
#include <stdarg.h>         //var_start, var_arg
#include <stdlib.h>         //
#include <limits>           //limits
//#include <termios.h>		// struct termios, tcgetattr, cfsetispeed, cfsetospeed, tcsetattr, IHFLOW, OHFLOW, IXOFF, IXON
//#include <sys/resource.h>	// setrlimit
#include <sys/types.h>      //Defined system types
#include <sys/stat.h>       //stat
#include <fcntl.h>		    //fcntl
#include <stdio.h>
#include <math.h>			//modf
#include <algorithm>    // std::sort
#include <limits.h>
#include <signal.h>


// net-snmp includes //
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-features.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include <net-snmp/types.h>
#include <net-snmp/mib_api.h>

#include <net-snmp/net-snmp-includes.h>

#include <net-snmp/library/fd_event_manager.h>
#include <net-snmp/library/large_fd_set.h>

#include <net-snmp/agent/agent_module_config.h>
#include <net-snmp/agent/mib_module_config.h>


#include <net-snmp/agent/mib_modules.h>

#include <net-snmp/agent/agent_trap.h>

#include <net-snmp/agent/table.h>
#include <net-snmp/agent/table_iterator.h>


//! \brief This is the default C++ namespaces.
using namespace std;

#endif // BASE_INCLUDES_H_
