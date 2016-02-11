#ifndef NET_SNMP_UTILITIES_H
#define NET_SNMP_UTILITIES_H

    /**
     *  Library API routines not specifically concerned with SNMP directly,
     *    but used more generally within the library, agent and other applications.
     *
     *  This also includes "standard" system routines, which are missing on
     *    particular O/S distributiones.
     */

#ifndef NET_SNMP_CONFIG_H
#error "Please include <siglog/net-snmp-config.h> before this file"
#endif

#include <siglog/types.h>

    /*
     *  For the initial release, this will just refer to the
     *  relevant UCD header files.
     *    In due course, the routines relevant to this area of the
     *  API will be identified, and listed here directly.
     *
     *  But for the time being, this header file is a placeholder,
     *  to allow application writers to adopt the new header file names.
     */

#include <siglog/library/snmp_api.h>
#include <siglog/library/snmp_client.h>
#if HAVE_GETOPT_H
#include <getopt.h>
#else
#include <siglog/library/getopt.h>
#endif

#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>         /* for in_addr_t */
#endif
#include <siglog/library/system.h>
#include <siglog/library/tools.h>
#include <siglog/library/asn1.h>      /* for counter64 */
#include <siglog/library/int64.h>

#include <siglog/library/mt_support.h>
/*  #include <siglog/library/snmp_locking.h>  */
#include <siglog/library/snmp_alarm.h>
#include <siglog/library/callback.h>
#include <siglog/library/data_list.h>
#include <siglog/library/oid_stash.h>
#include <siglog/library/snmp.h>
#include <siglog/library/snmp_impl.h>
#include <siglog/library/snmp-tc.h>
#include <siglog/library/check_varbind.h>
#include <siglog/library/container.h>
#include <siglog/library/container_binary_array.h>
#include <siglog/library/container_list_ssll.h>
#include <siglog/library/container_iterator.h>

#include <siglog/library/snmp_assert.h>

#include <siglog/version.h>

#endif                          /* NET_SNMP_UTILITIES_H */
