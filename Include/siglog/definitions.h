#ifndef NET_SNMP_DEFINITIONS_H
#define NET_SNMP_DEFINITIONS_H

    /**
     *  Defined constants, and other similar enumerations.
     */

#define MAX_OID_LEN	    128 /* max subid's in an oid */

#define ONE_SEC         1000000L

    /*
     *  For the initial release, this will just refer to the
     *  relevant UCD header files.
     *    In due course, the relevant definitions will be
     *  identified, and listed here directly.
     *
     *  But for the time being, this header file is primarily a placeholder,
     *  to allow application writers to adopt the new header file names.
     */

#include <siglog/types.h>     /* for oid */
#include <siglog/library/snmp_api.h>
#include <siglog/library/asn1.h>
#include <siglog/library/snmp_impl.h>
#include <siglog/library/snmp.h>
#include <siglog/library/snmp-tc.h>
/*
 * #include <siglog/library/libsnmp.h> 
 */

#endif                          /* NET_SNMP_DEFINITIONS_H */
