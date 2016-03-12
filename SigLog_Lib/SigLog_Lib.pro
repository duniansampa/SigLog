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
        snmp_client.cpp \
        mib.cpp \
        parse.cpp \
        snmp_api.cpp \
        snmp.cpp \
        snmp_auth.cpp \
        md5.cpp \
        snmp_parse_args.cpp \
        system.cpp \
        vacm.cpp \
        read_config.cpp \
        pkcs.cpp \
        snmp_debug.cpp \
        tools.cpp \
        snmp_logging.cpp \
        large_fd_set.cpp \
        snmp_openssl.cpp \
        snmpv3.cpp \
        lcd_time.cpp \
        keytools.cpp \
        scapi.cpp \
        default_store.cpp \
        snmp_alarm.cpp \
        data_list.cpp \
        oid_stash.cpp \
        fd_event_manager.cpp \
        check_varbind.cpp \
        mt_support.cpp \
        snmp_enum.cpp \
        snmp-tc.cpp \
        snmp_service.cpp \
        snmp_transport.cpp \
        transports/snmpUDPBaseDomain.cpp \
        transports/snmpUDPIPv4BaseDomain.cpp \
        transports/snmpTCPBaseDomain.cpp \
        transports/snmpSocketBaseDomain.cpp \
        transports/snmpIPv4BaseDomain.cpp \
        transports/snmpUDPDomain.cpp \
        transports/snmpTCPDomain.cpp \
        transports/snmpAliasDomain.cpp \
        transports/snmpUnixDomain.cpp \
        transports/snmpCallbackDomain.cpp \
        snmp_secmod.cpp \
        snmpusm.cpp \
        snmp_version.cpp \
        container_null.cpp \
        container_list_ssll.cpp \
        container_iterator.cpp \
        ucd_compat.cpp \
        dir_utils.cpp \
        file_utils.cpp \
        container.cpp \
        container_binary_array.cpp \
    int64.cpp \
    strlcat.cpp \
    text_utils.cpp \
    strlcpy.cpp \
    asn1.cpp \
    callback.cpp \
    cert_util.cpp

HEADERS += \
                     

DISTFILES += \
