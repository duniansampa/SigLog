#ifndef NET_SNMP_INCLUDES_H
#define NET_SNMP_INCLUDES_H

    /**
     *  Convenience header file to pull in the full
     *     Net-SNMP library API in one go, together with
     *     certain commonly-required system header files.
     */


    /*
     *  Common system header requirements
     */
#include <stdio.h>
#include <sys/types.h>
#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif

#ifndef NET_SNMP_CONFIG_H
#error "Please include <siglog/net-snmp-config.h> before this file"
#endif

#if HAVE_STRING_H
#include <string.h>
#else
#include <strings.h>
#endif

#if HAVE_STDLIB_H
#include <stdlib.h>
#endif
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#if HAVE_NETINET_IN_H
#include <netinet/in.h>
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

/*
 * Must be right after system headers, but before library code for best usage 
 */
#if HAVE_DMALLOC_H
#include <dmalloc.h>
#endif

  /*
   * The check for missing 'in_addr_t' is handled
   * within the main net-snmp-config.h file 
   */


    /*
     *  The full Net-SNMP API
     */
#include <siglog/definitions.h>
#include <siglog/types.h>

#include <siglog/library/getopt.h>
#include <siglog/utilities.h>
#include <siglog/session_api.h>
#include <siglog/pdu_api.h>
#include <siglog/mib_api.h>
#include <siglog/varbind_api.h>
#include <siglog/config_api.h>
#include <siglog/output_api.h>
#include <siglog/snmpv3_api.h>

#endif                          /* NET_SNMP_INCLUDES_H */
