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
    DEFINES += SIGLOG_AGENTLIB_LIBRARY
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
    target.extra = cd   $${libDir}; \
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

SOURCES +=  all_helpers.c \
        baby_steps.c \
        bulk_to_next.c \
        cache_handler.c \
        debug_handler.c \
        instance.c \
        mode_end_call.c \
        multiplexer.c \
        null.c \
        old_api.c \
        read_only.c \
        row_merge.c \
        scalar.c \
        scalar_group.c \
        serialize.c \
        snmp_get_statistic.c \
        stash_cache.c \
        stash_to_next.c \
        table.c \
        table_array.c \
        table_container.c \
        table_data.c \
        table_dataset.c \
        table_iterator.c \
        table_row.c \
        table_tdata.c \
        watcher.c \
        ../Agent/agent_handler.c \
        ../Agent/agent_index.c \
        ../Agent/agent_read_config.c \
        ../Agent/agent_registry.c \
        ../Agent/agent_sysORTable.c \
        ../Agent/agent_trap.c \
        ../Agent/kernel.c \
        ../Agent/snmp_agent.c \
        ../Agent/snmp_vars.c \
        ../SigLog_MibLib/snmpv3/usmConf.c \
        ../SigLog_MibLib/agentx/master.c \
        ../SigLog_MibLib/agentx/subagent.c \
        ../SigLog_MibLib/utilities/execute.c \
        ../SigLog_MibLib/utilities/iquery.c \
        ../SigLog_MibLib/mibII/vacm_conf.c \
        ../SigLog_MibLib/agentx/protocol.c \
        ../SigLog_MibLib/agentx/client.c \
        ../SigLog_MibLib/agentx/master_admin.c \
        ../SigLog_MibLib/agentx/agentx_config.c


DISTFILES += \
