/*
 *   dummy HAL memory module
 *      for systems not using any of the supported interfaces
 */
#include <siglog/net-snmp-config.h>
#include <siglog/net-snmp-includes.h>
#include <siglog/agent/net-snmp-agent-includes.h>
#include <siglog/agent/hardware/memory.h>


    /*
     * We can't load the memory usage statistics
     *   because we don't know how to do this!
     */
int netsnmp_mem_arch_load( netsnmp_cache *cache, void *magic ) {

    return 0;  /* or -1 ? */
}
