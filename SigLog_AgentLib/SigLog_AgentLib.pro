#-------------------------------------------------
#
# Project created by QtCreator 2016-01-26T12:01:37
#
#-------------------------------------------------

QT       -= gui

TARGET = siglogagent
TEMPLATE = lib

LIBS +=  -lsiglog -lm

unix {
    VERSION  = 1.0.0    # major.minor.patch
    DEFINES += SIGLOG_AGENTLresultadoIB_LIBRARY
    INCLUDEPATH += "$$PWD/../Include"
    INCLUDEPATH += "$$PWD/../Agent"
    INCLUDEPATH += "$$PWD/../SigLog_MibLib"
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

    #target.files += $${OUT_PWD}/siglogagent.so.1.0.0
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


HEADERS +=

SOURCES +=  all_helpers.cpp \
        baby_steps.cpp \
        bulk_to_next.cpp \
        cache_handler.cpp \
        debug_handler.cpp \
        instance.cpp \
        mode_end_call.cpp \
        multiplexer.cpp \
        null.cpp \
        old_api.cpp \
        read_only.cpp \
        row_merge.cpp \
        scalar.cpp \
        scalar_group.cpp \
        serialize.cpp \
        snmp_get_statistic.cpp \
        stash_cache.cpp \
        stash_to_next.cpp \
        table.cpp \
        table_array.cpp \
        table_container.cpp \
        table_data.cpp \
        table_dataset.cpp \
        table_iterator.cpp \
        table_row.cpp \
        table_tdata.cpp \
        watcher.cpp \
        agent_handler.cpp \
        agent_index.cpp \
        agent_read_config.cpp \
        agent_registry.cpp \
        agent_sysORTable.cpp \
        agent_trap.cpp \
        kernel.cpp \
        snmp_agent.cpp \
        snmp_vars.cpp \
        ../SigLog_MibLib/snmpv3/usmConf.cpp \
        ../SigLog_MibLib/agentx/master.cpp \
        ../SigLog_MibLib/agentx/subagent.cpp \
        ../SigLog_MibLib/utilities/execute.cpp \
        ../SigLog_MibLib/utilities/iquery.cpp \
        ../SigLog_MibLib/mibII/vacm_conf.cpp \
        ../SigLog_MibLib/agentx/protocol.cpp \
        ../SigLog_MibLib/agentx/client.cpp \
        ../SigLog_MibLib/agentx/master_admin.cpp \
        ../SigLog_MibLib/agentx/agentx_config.cpp


DISTFILES += \
