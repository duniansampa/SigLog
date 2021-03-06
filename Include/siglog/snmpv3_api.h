#ifndef NET_SNMP_SNMPV3_H
#define NET_SNMP_SNMPV3_H

    /**
     *  Library API routines concerned with SNMPv3 handling.
     *
     *  Most of these would typically not be used directly,
     *     but be invoked via version-independent API routines.
     */

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

#include <siglog/library/callback.h>
#include <siglog/library/snmpv3.h>
#include <siglog/library/transform_oids.h>
#include <siglog/library/keytools.h>
#include <siglog/library/scapi.h>
#include <siglog/library/lcd_time.h>
#ifdef NETSNMP_USE_INTERNAL_MD5
#include <siglog/library/md5.h>
#endif

#include <siglog/library/snmp_secmod.h>
#include <siglog/library/snmpv3-security-includes.h>

#endif                          /* NET_SNMP_SNMPV3_H */
