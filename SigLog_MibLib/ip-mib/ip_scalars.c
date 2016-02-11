/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.scalar.conf,v 1.8 2004/10/14 12:57:34 dts12 Exp $
 */

#include <siglog/net-snmp-config.h>
#include <siglog/net-snmp-features.h>
#include <siglog/net-snmp-includes.h>
#include <siglog/agent/net-snmp-agent-includes.h>

#include <siglog/data_access/ip_scalars.h>

#include "ip_scalars.h"

static int
handle_ipForwarding(netsnmp_mib_handler *handler,
                    netsnmp_handler_registration *reginfo,
                    netsnmp_agent_request_info *reqinfo,
                    netsnmp_request_info *requests);

static int
handle_ipDefaultTTL(netsnmp_mib_handler *handler,
                    netsnmp_handler_registration *reginfo,
                    netsnmp_agent_request_info *reqinfo,
                    netsnmp_request_info *requests);

static int
handle_ipv6IpForwarding(netsnmp_mib_handler *handler,
                        netsnmp_handler_registration *reginfo,
                        netsnmp_agent_request_info *reqinfo,
                        netsnmp_request_info *requests);

static int
handle_ipv6IpDefaultHopLimit(netsnmp_mib_handler *handler,
                             netsnmp_handler_registration *reginfo,
                             netsnmp_agent_request_info *reqinfo,
                             netsnmp_request_info *requests);

static int ipAddressSpinLockValue;

static int
handle_ipAddressSpinLock(netsnmp_mib_handler *handler,
                         netsnmp_handler_registration *reginfo,
                         netsnmp_agent_request_info *reqinfo,
                         netsnmp_request_info *requests);

/** Initializes the ip module */
void
init_ip_scalars(void)
{
    static oid 	    ipForwarding_oid[] = { 1, 3, 6, 1, 2, 1, 4, 1 };
    static oid 	    ipDefaultTTL_oid[] = { 1, 3, 6, 1, 2, 1, 4, 2 };
    static oid      ipv6IpForwarding_oid[] = { 1, 3, 6, 1, 2, 1, 4, 25 };
    static oid      ipv6IpDefaultHopLimit_oid[] = { 1, 3, 6, 1, 2, 1, 4, 26 };
    static oid      ipAddressSpinLock_oid[] = { 1, 3, 6, 1, 2, 1, 4, 33 };

    DEBUGMSGTL(("ip_scalar", "Initializing\n"));

    netsnmp_register_scalar(netsnmp_create_handler_registration
                             ("ipForwarding", handle_ipForwarding,
                              ipForwarding_oid,
                              OID_LENGTH(ipForwarding_oid),
                              HANDLER_CAN_RWRITE));
                                       
    netsnmp_register_scalar(netsnmp_create_handler_registration
                             ("ipDefaultTTL", handle_ipDefaultTTL,
                              ipDefaultTTL_oid,
                              OID_LENGTH(ipDefaultTTL_oid),
                              HANDLER_CAN_RWRITE));

    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("ipv6IpForwarding", handle_ipv6IpForwarding,
                             ipv6IpForwarding_oid,
                             OID_LENGTH(ipv6IpForwarding_oid),
                             HANDLER_CAN_RWRITE));

    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("ipv6IpDefaultHopLimit", handle_ipv6IpDefaultHopLimit,
                             ipv6IpDefaultHopLimit_oid,
                             OID_LENGTH(ipv6IpDefaultHopLimit_oid),
                             HANDLER_CAN_RWRITE));

    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("ipAddressSpinLock", handle_ipAddressSpinLock,
                             ipAddressSpinLock_oid,
                             OID_LENGTH(ipAddressSpinLock_oid),
                             HANDLER_CAN_RWRITE));

    /* Initialize spin lock with random value */
    ipAddressSpinLockValue = (int) random();

}

static int
handle_ipForwarding(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    int      rc;
    u_long   value;

    /* We are never called for a GETNEXT if it's registered as a
       "instance", as it's "magically" handled for us.  */

    /* a instance handler also only hands us one request at a time, so
       we don't need to loop over a list of requests; we'll only get one. */

    switch(reqinfo->mode) {

        case MODE_GET:
            rc = netsnmp_arch_ip_scalars_ipForwarding_get(&value);
            if (rc != 0) {
                netsnmp_set_request_error(reqinfo, requests,
                                      SNMP_NOSUCHINSTANCE);
            }
            else {
                value = value ? 1 : 2;
                snmp_set_var_typed_value(requests->requestvb, ASN_INTEGER,
                                     (u_char *)&value, sizeof(value));
            }
            break;

#ifndef NETSNMP_NO_WRITE_SUPPORT
        /*
         * SET REQUEST
         *
         * multiple states in the transaction.  See:
         * http://www.net-snmp.org/tutorial-5/toolkit/mib_module/set-actions.jpg
         */
        case MODE_SET_RESERVE1:
            break;

        case MODE_SET_RESERVE2:
            /*
             * store old info for undo later
             */
            rc = netsnmp_arch_ip_scalars_ipForwarding_get(&value);
            if (rc < 0) {
                netsnmp_set_request_error(reqinfo, requests,
                                          SNMP_ERR_NOCREATION);
            } else {
                u_long *value_save;
                value_save = netsnmp_memdup(&value, sizeof(value));
                if ( NULL == value_save )
                    netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_RESOURCEUNAVAILABLE);
                else
                    netsnmp_request_add_list_data(requests,
                                                  netsnmp_create_data_list
                                                  ("ipfw", value_save,
                                                  free));
	    }
            break;

        case MODE_SET_FREE:
            /* XXX: free resources allocated in RESERVE1 and/or
               RESERVE2.  Something failed somewhere, and the states
               below won't be called. */
            break;

        case MODE_SET_ACTION:
            /* XXX: perform the value change here */
            value =  *(requests->requestvb->val.integer);
            rc = netsnmp_arch_ip_scalars_ipForwarding_set(value);
            if ( 0 != rc ) {
                netsnmp_set_request_error(reqinfo, requests, rc);
            }
            break;

        case MODE_SET_COMMIT:
            break;

        case MODE_SET_UNDO:
             value =
                 *((u_long *) netsnmp_request_get_list_data(requests,
                                                            "ipfw"));
             rc = netsnmp_arch_ip_scalars_ipForwarding_set(value);
             if ( 0 != rc ) {
                 netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_UNDOFAILED);
             }
             break;
#endif /* !NETSNMP_NO_WRITE_SUPPORT */

        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_ipForwarding\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}


static int
handle_ipDefaultTTL(netsnmp_mib_handler *handler,
                    netsnmp_handler_registration *reginfo,
                    netsnmp_agent_request_info   *reqinfo,
                    netsnmp_request_info         *requests)
{
    int      rc;
    u_long   value;

    /* We are never called for a GETNEXT if it's registered as a
       "instance", as it's "magically" handled for us.  */

    /* a instance handler also only hands us one request at a time, so
       we don't need to loop over a list of requests; we'll only get one. */

    switch(reqinfo->mode) {

        case MODE_GET:
            rc = netsnmp_arch_ip_scalars_ipDefaultTTL_get(&value);
            if (rc != 0) {
                netsnmp_set_request_error(reqinfo, requests,
                                      SNMP_NOSUCHINSTANCE);
            }
            else {
                snmp_set_var_typed_value(requests->requestvb, ASN_INTEGER,
                                     (u_char *)&value, sizeof(value));
            }
            break;

#ifndef NETSNMP_NO_WRITE_SUPPORT
        /*
         * SET REQUEST
         *
         * multiple states in the transaction.  See:
         * http://www.net-snmp.org/tutorial-5/toolkit/mib_module/set-actions.jpg
         */
        case MODE_SET_RESERVE1:
            break;

        case MODE_SET_RESERVE2:
            /*
             * store old info for undo later
             */
            rc = netsnmp_arch_ip_scalars_ipDefaultTTL_get(&value);
            if (rc < 0) {
                netsnmp_set_request_error(reqinfo, requests,
                                          SNMP_ERR_NOCREATION);
            } else {
                u_long *value_save;
                value_save = netsnmp_memdup(&value, sizeof(value));
                if ( NULL == value_save )
                    netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_RESOURCEUNAVAILABLE);
                else
                    netsnmp_request_add_list_data(requests,
                                                  netsnmp_create_data_list
                                                  ("ipttl", value_save,
                                                  free));
	    }
            break;

        case MODE_SET_FREE:
            /* XXX: free resources allocated in RESERVE1 and/or
               RESERVE2.  Something failed somewhere, and the states
               below won't be called. */
            break;

        case MODE_SET_ACTION:
            /* XXX: perform the value change here */
            value =  *(requests->requestvb->val.integer);
            rc = netsnmp_arch_ip_scalars_ipDefaultTTL_set(value);
            if ( 0 != rc ) {
                netsnmp_set_request_error(reqinfo, requests, rc);
            }
            break;

        case MODE_SET_COMMIT:
            break;

        case MODE_SET_UNDO:
             value =
                 *((u_long *) netsnmp_request_get_list_data(requests,
                                                            "ipttl"));
             rc = netsnmp_arch_ip_scalars_ipDefaultTTL_set(value);
             if ( 0 != rc ) {
                 netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_UNDOFAILED);
             }
             break;
#endif /* !NETSNMP_NO_WRITE_SUPPORT */

        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_ipDefaultTTL\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}


static int
handle_ipv6IpForwarding(netsnmp_mib_handler *handler,
                        netsnmp_handler_registration *reginfo,
                        netsnmp_agent_request_info *reqinfo,
                        netsnmp_request_info *requests)
{
    int      rc;
    u_long   value;

    /*
     * We are never called for a GETNEXT if it's registered as a
     * "instance", as it's "magically" handled for us.  
     */

    /*
     * a instance handler also only hands us one request at a time, so
     * we don't need to loop over a list of requests; we'll only get one. 
     */
    switch (reqinfo->mode) {

    case MODE_GET:
        rc = netsnmp_arch_ip_scalars_ipv6IpForwarding_get(&value);
        if (rc != 0) {
            netsnmp_set_request_error(reqinfo, requests,
                                      SNMP_NOSUCHINSTANCE);
        }
        else {
            value = value ? 1 : 2;
            snmp_set_var_typed_value(requests->requestvb, ASN_INTEGER,
                                     (u_char *)&value, sizeof(value));
        }
        break;

#ifndef NETSNMP_NO_WRITE_SUPPORT
        /*
         * SET REQUEST
         *
         * multiple states in the transaction.  See:
         * http://www.net-snmp.org/tutorial-5/toolkit/mib_module/set-actions.jpg
         */
    case MODE_SET_RESERVE1:
        break;

    case MODE_SET_RESERVE2:
        /*
         * store old info for undo later 
         */
        rc = netsnmp_arch_ip_scalars_ipv6IpForwarding_get(&value);
        if (rc < 0) {
            netsnmp_set_request_error(reqinfo, requests,
                                      SNMP_ERR_NOCREATION);
        }
        else {
            u_long *value_save;

            value_save = netsnmp_memdup(&value, sizeof(value));
            if ( NULL == value_save ) {
                netsnmp_set_request_error(reqinfo, requests,
                                          SNMP_ERR_RESOURCEUNAVAILABLE);
            }
            else {
                netsnmp_request_add_list_data(requests,
                                              netsnmp_create_data_list
                                              ("ip6fw", value_save,
                                               free));
            }
        }
        break;

    case MODE_SET_FREE:
        break;

    case MODE_SET_ACTION:
        value =  *(requests->requestvb->val.integer);
        rc = netsnmp_arch_ip_scalars_ipv6IpForwarding_set(value);
        if ( 0 != rc ) {
            netsnmp_set_request_error(reqinfo, requests, rc );
        }
        break;

    case MODE_SET_COMMIT:
        break;

    case MODE_SET_UNDO:
        value =
            *((u_long *) netsnmp_request_get_list_data(requests,
                                                       "ip6fw"));
        rc = netsnmp_arch_ip_scalars_ipv6IpForwarding_set(value);
        if ( 0 != rc ) {
            netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_UNDOFAILED);
        }
        break;
#endif /* !NETSNMP_NO_WRITE_SUPPORT */

    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR, "unknown mode (%d) in handle_ipv6IpForwarding\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}


static int
handle_ipAddressSpinLock(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    long   value;

    /* We are never called for a GETNEXT if it's registered as a
       "instance", as it's "magically" handled for us.  */

    /* a instance handler also only hands us one request at a time, so
       we don't need to loop over a list of requests; we'll only get one. */

    switch(reqinfo->mode) {

        case MODE_GET:
            snmp_set_var_typed_value(requests->requestvb, ASN_INTEGER,
                                     (u_char *)&ipAddressSpinLockValue, 
                                     sizeof(ipAddressSpinLockValue));
            break;

#ifndef NETSNMP_NO_WRITE_SUPPORT
        /*
         * SET REQUEST
         *
         * multiple states in the transaction.  See:
         * http://www.net-snmp.org/tutorial-5/toolkit/mib_module/set-actions.jpg
         */
        case MODE_SET_RESERVE1:
        case MODE_SET_RESERVE2:
            /* just check the value */
            value =  *(requests->requestvb->val.integer);
            if (value != ipAddressSpinLockValue)
                netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_INCONSISTENTVALUE);
            break;

        case MODE_SET_FREE:
            break;

        case MODE_SET_ACTION:
            /* perform the final spinlock check and increase its value */
            value =  *(requests->requestvb->val.integer);
            if (value != ipAddressSpinLockValue) {
                netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_INCONSISTENTVALUE);
            } else {
                ipAddressSpinLockValue++;
                /* and check it for overflow */
                if (ipAddressSpinLockValue > 2147483647 || ipAddressSpinLockValue < 0)
                    ipAddressSpinLockValue = 0;
            }
            break;

        case MODE_SET_COMMIT:
            break;

        case MODE_SET_UNDO:
             break;
#endif /* !NETSNMP_NO_WRITE_SUPPORT */

        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_ipAddressSpinLock\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}


static int
handle_ipv6IpDefaultHopLimit(netsnmp_mib_handler *handler,
                             netsnmp_handler_registration *reginfo,
                             netsnmp_agent_request_info *reqinfo,
                             netsnmp_request_info *requests)
{
    u_long          value;
    int             rc;
    /*
     * We are never called for a GETNEXT if it's registered as a
     * "instance", as it's "magically" handled for us.  
     */

    /*
     * a instance handler also only hands us one request at a time, so
     * we don't need to loop over a list of requests; we'll only get one. 
     */

    switch (reqinfo->mode) {

    case MODE_GET:

        rc = netsnmp_arch_ip_scalars_ipv6IpDefaultHopLimit_get(&value);
        if (rc != 0) {
            netsnmp_set_request_error(reqinfo, requests,
                                  SNMP_NOSUCHINSTANCE);
        }
        else {
            snmp_set_var_typed_value(requests->requestvb, ASN_INTEGER,
                                 (u_char *)&value, sizeof(value));
        }

        break;

#ifdef NOTYET
        /*
         * SET REQUEST
         *
         * multiple states in the transaction.  See:
         * http://www.net-snmp.org/tutorial-5/toolkit/mib_module/set-actions.jpg
         */
    case MODE_SET_RESERVE1:
        /*
         * or you could use netsnmp_check_vb_type_and_size instead 
         */
        rc = netsnmp_check_vb_type(requests->requestvb, ASN_INTEGER);
        if (rc != SNMP_ERR_NOERROR) {
            netsnmp_set_request_error(reqinfo, requests, rc);
        }
        break;

    case MODE_SET_RESERVE2:
        /*
         * XXX malloc "undo" storage buffer 
         */
        if ( /* XXX if malloc, or whatever, failed: */ ) {
            netsnmp_set_request_error(reqinfo, requests,
                                      SNMP_ERR_RESOURCEUNAVAILABLE);
        }
        break;

    case MODE_SET_FREE:
        /*
         * XXX: free resources allocated in RESERVE1 and/or
         * RESERVE2.  Something failed somewhere, and the states
         * below won't be called. 
         */
        break;

    case MODE_SET_ACTION:
        /*
         * XXX: perform the value change here 
         */
        if ( /* XXX: error? */ ) {
            netsnmp_set_request_error(reqinfo, requests, /* some error */
                                      );
        }
        break;

    case MODE_SET_COMMIT:
        /*
         * XXX: delete temporary storage 
         */
        if ( /* XXX: error? */ ) {
            /*
             * try _really_really_ hard to never get to this point 
             */
            netsnmp_set_request_error(reqinfo, requests,
                                      SNMP_ERR_COMMITFAILED);
        }
        break;

    case MODE_SET_UNDO:
        /*
         * XXX: UNDO and return to previous value for the object 
         */
        if ( /* XXX: error? */ ) {
            /*
             * try _really_really_ hard to never get to this point 
             */
            netsnmp_set_request_error(reqinfo, requests,
                                      SNMP_ERR_UNDOFAILED);
        }
        break;
#endif

    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        snmp_log(LOG_ERR,
                 "unknown mode (%d) in handle_ipv6IpDefaultHopLimit\n",
                 reqinfo->mode);
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}
