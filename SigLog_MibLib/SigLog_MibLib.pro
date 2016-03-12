#-------------------------------------------------
#
# Project created by QtCreator 2016-01-26T12:01:37
#
#-------------------------------------------------

QT       -= gui

TARGET = siglogmib
TEMPLATE = lib
LIBS += -lsiglogagent  -lsiglog  -ldl -lrpm -lrpmio  -lm

unix {
    VERSION  = 1.0.0    # major.minor.patch
    DEFINES += SIGLOG_MIBLIB_LIBRARY
    INCLUDEPATH += "$$PWD/../Include"
    INCLUDEPATH += "$$PWD/../Agent"
    INCLUDEPATH += "$$PWD"
    QMAKE_CFLAGS += -fno-strict-aliasing -g -O2
}


unix {
     usrDir         = /usr/
     libDir         = /usr/lib64/
     incDir         = /usr/include/
     origIncDir     = $$PWD/../Include/
     obj            = $${TEMPLATE}$${TARGET}.so.1.0.0
     objLink        = $${TEMPLATE}$${TARGET}.so
     objDir         = $${OUT_PWD}
     target.path    = ./

    #target.files += $${OUT_PWD}/siglogmib.so.1.0.0
    target.extra = @cd   $${libDir}; \
                   sudo rm $${objLink} $${obj}; \
                   cd -; \
                   echo "---- Copiando arquivos...----"; \
                   sudo cp -r   $${origIncDir}*    $${incDir}; \
                   echo "---- Arquivos copiado para $${incDir}"; \
                   echo "---- Instalando bibliotecas...----"; \
                   sudo cp $${objDir}/$${obj} $${libDir}; \
                   sudo chmod 755   $${libDir}/$${obj}; \
                   cd   $${libDir}; \
                   sudo ln -s $${obj} $${objLink}; \
                   cd -; \
                   echo "---- Instalado no $${libDir}"; \
                   sudo ldconfig; \
                   echo "---- Linker atualizado com sucesso ----"
    #g++ --print-search-dirs
    INSTALLS += target
}


SOURCES +=  snmpv3/snmpMPDStats_5_5.cpp \
            snmpv3/usmStats_5_5.cpp \
            snmpv3/snmpEngine.cpp \
            snmpv3/usmUser.cpp \
            mibII/snmp_mib_5_5.cpp \
            mibII/system_mib.cpp \
            mibII/sysORTable.cpp \
            mibII/vacm_vars.cpp \
            mibII/setSerialNo.cpp \
            mibII/at.cpp \
            mibII/ip.cpp \
            mibII/tcp.cpp \
            mibII/icmp.cpp \
            mibII/udp.cpp \
            ucd-snmp/disk_hw.cpp \
            ucd-snmp/proc.cpp \
            ucd-snmp/versioninfo.cpp \
            ucd-snmp/pass.cpp \
            ucd-snmp/pass_persist.cpp \
            ucd-snmp/loadave.cpp \
            agent/extend.cpp \
            ucd-snmp/errormib.cpp \
            ucd-snmp/file.cpp \
            ucd-snmp/dlmod.cpp \
            ucd-snmp/proxy.cpp \
            ucd-snmp/logmatch.cpp \
            ucd-snmp/memory.cpp \
            ucd-snmp/vmstat.cpp \
            notification/snmpNotifyTable.cpp \
            notification/snmpNotifyFilterProfileTable.cpp \
            notification-log-mib/notification_log.cpp \
            target/target_counters_5_5.cpp \
            target/snmpTargetAddrEntry.cpp \
            target/snmpTargetParamsEntry.cpp \
            target/target.cpp \
            agent/nsTransactionTable.cpp \
            agent/nsModuleTable.cpp \
            agent/nsDebug.cpp \
            agent/nsCache.cpp \
            agent/nsLogging.cpp \
            agent/nsVacmAccessTable.cpp \
            disman/event/mteScalars.cpp \
            disman/event/mteTrigger.cpp \
            disman/event/mteTriggerTable.cpp \
            disman/event/mteTriggerDeltaTable.cpp \
            disman/event/mteTriggerExistenceTable.cpp \
            disman/event/mteTriggerBooleanTable.cpp \
            disman/event/mteTriggerThresholdTable.cpp \
            disman/event/mteTriggerConf.cpp \
            disman/event/mteEvent.cpp \
            disman/event/mteEventTable.cpp \
            disman/event/mteEventSetTable.cpp \
            disman/event/mteEventNotificationTable.cpp \
            disman/event/mteEventConf.cpp \
            disman/event/mteObjects.cpp \
            disman/event/mteObjectsTable.cpp \
            disman/event/mteObjectsConf.cpp \
            disman/schedule/schedCore.cpp \
            disman/schedule/schedConf.cpp \
            disman/schedule/schedTable.cpp \
            utilities/override.cpp \
            host/hrh_storage.cpp \
            host/hrh_filesys.cpp \
            host/hrSWInstalledTable.cpp \
            host/hrSWRunTable.cpp \
            host/hr_system.cpp \
            host/hr_device.cpp \
            host/hr_other.cpp \
            host/hr_proc.cpp \
            host/hr_network.cpp \
            host/hr_print.cpp \
            host/hr_disk.cpp \
            host/hr_partition.cpp \
            util_funcs/header_generic.cpp \
            mibII/updates.cpp \
            util_funcs.cpp \
            mibII/vacm_context.cpp \
            mibII/kernel_linux.cpp \
            mibII/ipAddr.cpp \
            mibII/var_route.cpp \
            mibII/route_write.cpp \
            mibII/tcpTable.cpp \
            mibII/udpTable.cpp \
            ip-mib/ip_scalars.cpp \
            util_funcs/header_simple_table.cpp \
            util_funcs/restart.cpp \
            ucd-snmp/pass_common.cpp \
            header_complex.cpp \
            snmp-notification-mib/snmpNotifyFilterTable/snmpNotifyFilterTable.cpp \
            host/data_access/swinst.cpp \
            host/data_access/swrun.cpp \
            host/hrSWRunPerfTable.cpp \
            if-mib/ifTable/ifTable.cpp \
            if-mib/ifXTable/ifXTable.cpp \
            ip-mib/ipAddressTable/ipAddressTable.cpp \
            ip-mib/ipAddressPrefixTable/ipAddressPrefixTable.cpp \
            ip-mib/ipDefaultRouterTable/ipDefaultRouterTable.cpp \
            ip-mib/inetNetToMediaTable/inetNetToMediaTable.cpp \
            ip-mib/inetNetToMediaTable/inetNetToMediaTable_interface.cpp \
            ip-mib/inetNetToMediaTable/inetNetToMediaTable_data_access.cpp \
            ip-mib/ipSystemStatsTable/ipSystemStatsTable.cpp \
            ip-mib/ipSystemStatsTable/ipSystemStatsTable_interface.cpp \
            ip-mib/ipSystemStatsTable/ipSystemStatsTable_data_access.cpp \
            ip-mib/ipv6ScopeZoneIndexTable/ipv6ScopeZoneIndexTable.cpp \
            ip-mib/ipIfStatsTable/ipIfStatsTable.cpp \
            ip-mib/ipIfStatsTable/ipIfStatsTable_interface.cpp \
            ip-mib/ipIfStatsTable/ipIfStatsTable_data_access.cpp \
            ip-forward-mib/ipCidrRouteTable/ipCidrRouteTable.cpp \
            ip-forward-mib/inetCidrRouteTable/inetCidrRouteTable.cpp \
            tcp-mib/tcpConnectionTable/tcpConnectionTable.cpp \
            tcp-mib/tcpListenerTable/tcpListenerTable.cpp \
            udp-mib/udpEndpointTable/udpEndpointTable.cpp \
            hardware/fsys/hw_fsys.cpp \
            hardware/fsys/fsys_mntent.cpp \
            hardware/memory/hw_mem.cpp \
            hardware/memory/memory_linux.cpp \
            hardware/cpu/cpu.cpp \
            hardware/cpu/cpu_linux.cpp \
            snmp-notification-mib/snmpNotifyFilterTable/snmpNotifyFilterTable_interface.cpp \
            snmp-notification-mib/snmpNotifyFilterTable/snmpNotifyFilterTable_data_access.cpp \
            host/data_access/swinst_rpm.cpp \
            host/data_access/swrun_procfs_status.cpp \
            if-mib/data_access/interface.cpp \
            if-mib/ifTable/ifTable_interface.cpp \
            if-mib/ifTable/ifTable_data_access.cpp \
            if-mib/ifXTable/ifXTable_interface.cpp \
            if-mib/ifXTable/ifXTable_data_access.cpp \
            ip-mib/ipAddressTable/ipAddressTable_interface.cpp \
            ip-mib/ipAddressTable/ipAddressTable_data_access.cpp \
            ip-mib/ipAddressPrefixTable/ipAddressPrefixTable_interface.cpp \
            ip-mib/ipAddressPrefixTable/ipAddressPrefixTable_data_access.cpp \
            ip-mib/ipDefaultRouterTable/ipDefaultRouterTable_interface.cpp \
            ip-mib/ipDefaultRouterTable/ipDefaultRouterTable_data_access.cpp \
            ip-mib/ipDefaultRouterTable/ipDefaultRouterTable_data_get.cpp \
            ip-mib/data_access/arp_common.cpp \
            ip-mib/data_access/arp_netlink.cpp \
            ip-mib/data_access/systemstats_common.cpp \
            ip-mib/data_access/systemstats_linux.cpp \
            ip-mib/data_access/scalars_linux.cpp \
            ip-mib/ipv6ScopeZoneIndexTable/ipv6ScopeZoneIndexTable_interface.cpp \
            ip-mib/ipv6ScopeZoneIndexTable/ipv6ScopeZoneIndexTable_data_access.cpp \
            ip-mib/ipIfStatsTable/ipIfStatsTable_data_get.cpp \
            ip-forward-mib/ipCidrRouteTable/ipCidrRouteTable_interface.cpp \
            ip-forward-mib/ipCidrRouteTable/ipCidrRouteTable_data_access.cpp \
            ip-forward-mib/inetCidrRouteTable/inetCidrRouteTable_interface.cpp \
            ip-forward-mib/inetCidrRouteTable/inetCidrRouteTable_data_access.cpp \
            tcp-mib/data_access/tcpConn_common.cpp \
            tcp-mib/data_access/tcpConn_linux.cpp \
            util_funcs/get_pid_from_inode.cpp \
            tcp-mib/tcpConnectionTable/tcpConnectionTable_interface.cpp \
            tcp-mib/tcpConnectionTable/tcpConnectionTable_data_access.cpp \
            tcp-mib/tcpListenerTable/tcpListenerTable_interface.cpp \
            tcp-mib/tcpListenerTable/tcpListenerTable_data_access.cpp \
            udp-mib/udpEndpointTable/udpEndpointTable_interface.cpp \
            udp-mib/udpEndpointTable/udpEndpointTable_data_access.cpp \
            if-mib/data_access/interface_linux.cpp \
            if-mib/data_access/interface_ioctl.cpp \
            ip-mib/data_access/ipaddress_common.cpp \
            ip-mib/data_access/ipaddress_linux.cpp \
            ip-mib/data_access/defaultrouter_common.cpp \
            ip-mib/data_access/defaultrouter_linux.cpp \
            ip-mib/data_access/ipv6scopezone_common.cpp \
            ip-mib/data_access/ipv6scopezone_linux.cpp \
            ip-forward-mib/data_access/route_common.cpp \
            ip-forward-mib/data_access/route_linux.cpp \
            ip-forward-mib/data_access/route_ioctl.cpp \
            udp-mib/data_access/udp_endpoint_common.cpp \
            udp-mib/data_access/udp_endpoint_linux.cpp \
            ip-mib/data_access/ipaddress_ioctl.cpp \
            ../Agent/mib_modules.cpp \
            ../Agent/auto_nlist.cpp


DISTFILES += \

HEADERS +=
