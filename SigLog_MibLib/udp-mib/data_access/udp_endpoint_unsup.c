/*
 * udpEndpointTable MIB architecture support
 */
#include <siglog/net-snmp-config.h>
#include <siglog/net-snmp-features.h>
#include <siglog/net-snmp-includes.h>
#include <siglog/agent/net-snmp-agent-includes.h>
#include <siglog/library/file_utils.h>
#include <siglog/library/text_utils.h>
#include <siglog/data_access/ipaddress.h>
#include <siglog/data_access/udp_endpoint.h>

/*
 * initialize arch specific storage
 *
 * @retval  0: success
 * @retval <0: error
 */
#ifndef NETSNMP_FEATURE_REMOVE_UDP_ENDPOINT_WRITABLE
int
netsnmp_arch_udp_endpoint_entry_init(netsnmp_udp_endpoint_entry *entry)
{
    return 0;
}

/*
 * cleanup arch specific storage
 */
void
netsnmp_arch_udp_endpoint_entry_cleanup(netsnmp_udp_endpoint_entry *entry)
{
}

/*
 * copy arch specific storage
 */
int
netsnmp_arch_udp_endpoint_entry_copy(netsnmp_udp_endpoint_entry *lhs,
                                  netsnmp_udp_endpoint_entry *rhs)
{
    return 0;
}

/*
 * delete an entry
 */
int
netsnmp_arch_udp_endpoint_delete(netsnmp_udp_endpoint_entry *entry)
{
    return -1;
}
#endif /* NETSNMP_FEATURE_REMOVE_UDP_ENDPOINT_WRITABLE */


/**
 *
 * @retval  0 no errors
 * @retval !0 errors
 */
int
netsnmp_arch_udp_endpoint_container_load(netsnmp_container *container,
                                    u_int load_flags )
{
    return -1;
}
