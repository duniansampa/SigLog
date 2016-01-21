#-------------------------------------------------
#
# Project created by QtCreator 2016-01-18T03:07:08
#
#-------------------------------------------------

QT       -= gui

TARGET = LibNetSnmp
TEMPLATE = lib

DEFINES += LIBNETSNMP_LIBRARY

INCLUDEPATH += $$PWD/../Include

SOURCES += \
    asn1.c \
    callback.c \
    cert_util.c \
    check_varbind.c \
    closedir.c \
    container.c \
    container_binary_array.c \
    container_iterator.c \
    container_list_ssll.c \
    container_null.c \
    data_list.c \
    default_store.c \
    dir_utils.c \
    fd_event_manager.c \
    file_utils.c \
    getopt.c \
    gettimeofday.c \
    inet_ntop.c \
    inet_pton.c \
    int64.c \
    keytools.c \
    large_fd_set.c \
    lcd_time.c \
    md5.c \
    mib.c \
    mt_support.c \
    oid_stash.c \
    opendir.c \
    parse.c \
    pkcs.c \
    read_config.c \
    readdir.c \
    scapi.c \
    snmp.c \
    snmp_alarm.c \
    snmp_api.c \
    snmp_auth.c \
    snmp_client.c \
    snmp_debug.c \
    snmp_enum.c \
    snmpksm.c \
    snmp_logging.c \
    snmp_openssl.c \
    snmp_parse_args.c \
    snmp_secmod.c \
    snmp_service.c \
    snmp-tc.c \
    snmp_transport.c \
    snmptsm.c \
    snmpusm.c \
    snmpv3.c \
    snmp_version.c \
    snprintf.c \
    strlcat.c \
    strlcpy.c \
    strtok_r.c \
    strtol.c \
    strtoul.c \
    strtoull.c \
    system.c \
    text_utils.c \
    tools.c \
    ucd_compat.c \
    vacm.c \
    winpipe.c \
    winservice.c

HEADERS += \
    inet_ntop.h \
    inet_pton.h \
    snmpsm_init.h \
    snmpsm_shutdown.h \
    ucd-snmp-includes.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    MSG00001.bin \
    LibNetSnmp.pro.user \
    winservice.mc \
    winservice.rc \
    winservicerc.rc
