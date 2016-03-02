#-------------------------------------------------
#
# Project created by QtCreator 2016-01-18T03:07:08
#
#-------------------------------------------------

QT       -= gui

TARGET = siglog
TEMPLATE = lib

LIBS += -lcrypto -lm

unix {
    VERSION  = 1.0.0    # major.minor.patch
    DEFINES += SIGLOG_LIBRARY
    INCLUDEPATH += "$$PWD/../Include"
    QMAKE_CFLAGS += -fno-strict-aliasing -g -O2
}


unix {
     usrDir         = /usr/
     libDir         = /usr/lib64/
     incDir         = /usr/include/
     origIncDilnetsnmphelpersr     = $$PWD/../Include/
     obj            = $${TEMPLATE}$${TARGET}.so.1.0.0
     objLink        = $${TEMPLATE}$${TARGET}.so
     objDir         = $${OUT_PWD}
     target.path    = ./

#target.files += $${OUT_PWD}/libsiglog.so.1.0.0
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

SOURCES += \
        snmp_client.c \
        mib.c \
        parse.c \
        snmp_api.c \
        snmp.c \
        snmp_auth.c \
        asn1.c \
        md5.c \
        snmp_parse_args.c \
        system.c \
        vacm.c \
        int64.c \
        read_config.c \
        pkcs.c \
        snmp_debug.c \
        tools.c \
        snmp_logging.c \
        text_utils.c \
        large_fd_set.c \
        cert_util.c \
        snmp_openssl.c \
        snmpv3.c \
        lcd_time.c \
        keytools.c \
        scapi.c \
        callback.c \
        default_store.c \
        snmp_alarm.c \
        data_list.c \
        oid_stash.c \
        fd_event_manager.c \
        check_varbind.c \
        mt_support.c \
        snmp_enum.c \
        snmp-tc.c \
        snmp_service.c \
        snprintf.c \
        snmp_transport.c \
        transports/snmpUDPBaseDomain.c \
        transports/snmpUDPIPv4BaseDomain.c \
        transports/snmpTCPBaseDomain.c \
        transports/snmpSocketBaseDomain.c \
        transports/snmpIPv4BaseDomain.c \
        transports/snmpUDPDomain.c \
        transports/snmpTCPDomain.c \
        transports/snmpAliasDomain.c \
        transports/snmpUnixDomain.c \
        transports/snmpCallbackDomain.c \
        snmp_secmod.c \
        snmpusm.c \
        snmp_version.c \
        container_null.c \
        container_list_ssll.c \
        container_iterator.c \
        ucd_compat.c \
        strlcat.c \
        strlcpy.c \
        dir_utils.c \
        file_utils.c \
        container.c \
        container_binary_array.c

HEADERS +=

DISTFILES += \
