/*
 * Note: this file originally auto-generated by mib2c using
 *  $
 */

#include <siglog/net-snmp-config.h>
#include <siglog/net-snmp-includes.h>
#include <siglog/agent/net-snmp-agent-includes.h>
#include <siglog/agent/table_container.h>
#include "sctpLookupRemPrimIPAddrTable.h"

static netsnmp_container *sctpLookupRemPrimIPAddrTable_container;
static netsnmp_table_registration_info *table_info;

/** Initializes the sctpLookupRemPrimIPAddrTable module */
void
init_sctpLookupRemPrimIPAddrTable(void)
{
    /*
     * here we initialize all the tables we're planning on supporting 
     */
    initialize_table_sctpLookupRemPrimIPAddrTable();
}

void
shutdown_sctpLookupRemPrimIPAddrTable(void)
{
    shutdown_table_sctpLookupRemPrimIPAddrTable();
}

/** Initialize the sctpLookupRemPrimIPAddrTable table by defining its contents and how it's structured */
void
initialize_table_sctpLookupRemPrimIPAddrTable(void)
{
    static oid      sctpLookupRemPrimIPAddrTable_oid[] =
        { 1, 3, 6, 1, 2, 1, 104, 1, 9 };
    size_t          sctpLookupRemPrimIPAddrTable_oid_len =
        OID_LENGTH(sctpLookupRemPrimIPAddrTable_oid);
    netsnmp_handler_registration *reg = NULL;
    netsnmp_mib_handler *handler = NULL;
    netsnmp_container *container = NULL;

    reg =
        netsnmp_create_handler_registration("sctpLookupRemPrimIPAddrTable",
                                            sctpLookupRemPrimIPAddrTable_handler,
                                            sctpLookupRemPrimIPAddrTable_oid,
                                            sctpLookupRemPrimIPAddrTable_oid_len,
                                            HANDLER_CAN_RONLY);
    if (NULL == reg) {
        snmp_log(LOG_ERR,
                 "error creating handler registration for sctpLookupRemPrimIPAddrTable\n");
        goto bail;
    }

    container =
        netsnmp_container_find
        ("sctpLookupRemPrimIPAddrTable:table_container");
    if (NULL == container) {
        snmp_log(LOG_ERR,
                 "error creating container for sctpLookupRemPrimIPAddrTable\n");
        goto bail;
    }
    sctpLookupRemPrimIPAddrTable_container = container;

    table_info = SNMP_MALLOC_TYPEDEF(netsnmp_table_registration_info);
    if (NULL == table_info) {
        snmp_log(LOG_ERR,
                 "error allocating table registration for sctpLookupRemPrimIPAddrTable\n");
        goto bail;
    }
    netsnmp_table_helper_add_indexes(table_info, ASN_INTEGER,   /* index: sctpAssocRemPrimAddrType */
                                     ASN_OCTET_STR,     /* index: sctpAssocRemPrimAddr */
                                     ASN_UNSIGNED,      /* index: sctpAssocId */
                                     0);
    table_info->min_column = COLUMN_SCTPLOOKUPREMPRIMIPADDRSTARTTIME;
    table_info->max_column = COLUMN_SCTPLOOKUPREMPRIMIPADDRSTARTTIME;

    /*************************************************
     *
     * inject container_table helper
     */
    handler = netsnmp_container_table_handler_get(table_info, container,
                                                  TABLE_CONTAINER_KEY_NETSNMP_INDEX);
    if (NULL == handler) {
        snmp_log(LOG_ERR,
                 "error allocating table registration for sctpLookupRemPrimIPAddrTable\n");
        goto bail;
    }
    if (SNMPERR_SUCCESS != netsnmp_inject_handler(reg, handler)) {
        snmp_log(LOG_ERR,
                 "error injecting container_table handler for sctpLookupRemPrimIPAddrTable\n");
        goto bail;
    }
    handler = NULL;             /* reg has it, will reuse below */

    /*
     * register the table
     */
    if (SNMPERR_SUCCESS != netsnmp_register_table(reg, table_info)) {
        snmp_log(LOG_ERR,
                 "error registering table handler for sctpLookupRemPrimIPAddrTable\n");
        reg = NULL; /* it was freed inside netsnmp_register_table */
        goto bail;
    }

    return;                     /* ok */

    /*
     * Some error occurred during registration. Clean up and bail.
     */
  bail:                        /* not ok */

    if (handler)
        netsnmp_handler_free(handler);

    if (table_info)
        netsnmp_table_registration_info_free(table_info);

    if (container)
        CONTAINER_FREE(container);

    if (reg)
        netsnmp_handler_registration_free(reg);
}

void
shutdown_table_sctpLookupRemPrimIPAddrTable(void)
{
    if (table_info) {
        netsnmp_table_registration_info_free(table_info);
	table_info = NULL;
    }
    sctpLookupRemPrimIPAddrTable_container_clear
        (sctpLookupRemPrimIPAddrTable_container);
}

/** handles requests for the sctpLookupRemPrimIPAddrTable table */
int
sctpLookupRemPrimIPAddrTable_handler(netsnmp_mib_handler *handler,
                                     netsnmp_handler_registration *reginfo,
                                     netsnmp_agent_request_info *reqinfo,
                                     netsnmp_request_info *requests)
{

    netsnmp_request_info *request;
    netsnmp_table_request_info *table_info;
    sctpLookupRemPrimIPAddrTable_entry *table_entry;

    switch (reqinfo->mode) {
        /*
         * Read-support (also covers GetNext requests)
         */
    case MODE_GET:
        for (request = requests; request; request = request->next) {
            if (request->processed)
                continue;
            table_entry = (sctpLookupRemPrimIPAddrTable_entry *)
                netsnmp_container_table_extract_context(request);
            table_info = netsnmp_extract_table_info(request);
            if ((NULL == table_entry) || (NULL == table_info)) {
                snmp_log(LOG_ERR,
                         "could not extract table entry or info for sctpLookupRemPrimIPAddrTable\n");
                snmp_set_var_typed_value(request->requestvb,
                                         SNMP_ERR_GENERR, NULL, 0);
                continue;
            }

            switch (table_info->colnum) {
            case COLUMN_SCTPLOOKUPREMPRIMIPADDRSTARTTIME:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb,
                                           ASN_TIMETICKS,
                                           table_entry->sctpLookupRemPrimIPAddrStartTime);
                break;
            default:
                netsnmp_set_request_error(reqinfo, request,
                                          SNMP_NOSUCHOBJECT);
                break;
            }
        }
        break;

    }
    return SNMP_ERR_NOERROR;
}

sctpLookupRemPrimIPAddrTable_entry *
sctpLookupRemPrimIPAddrTable_entry_create(void)
{
    sctpLookupRemPrimIPAddrTable_entry *entry =
        SNMP_MALLOC_TYPEDEF(sctpLookupRemPrimIPAddrTable_entry);
    if (entry != NULL) {
        entry->oid_index.len =
            SCTP_LOOKUP_REM_PRIM_IP_ADDR_TABLE_INDEX_SIZE;
        entry->oid_index.oids = entry->oid_tmp;
    }

    return entry;
}

int
sctpLookupRemPrimIPAddrTable_entry_update_index
    (sctpLookupRemPrimIPAddrTable_entry * entry)
{
    netsnmp_variable_list var_sctpAssocRemPrimAddrType;
    netsnmp_variable_list var_sctpAssocRemPrimAddr;
    netsnmp_variable_list var_sctpAssocId;
    int             err = 0;

    /*
     * prepare the value to be converted 
     */
    memset(&var_sctpAssocRemPrimAddrType, 0,
           sizeof(var_sctpAssocRemPrimAddrType));
    var_sctpAssocRemPrimAddrType.type = ASN_UNSIGNED;
    var_sctpAssocRemPrimAddrType.next_variable = &var_sctpAssocRemPrimAddr;
    snmp_set_var_value(&var_sctpAssocRemPrimAddrType,
                       (u_char *) & entry->sctpAssocRemPrimAddrType,
                       sizeof(entry->sctpAssocRemPrimAddrType));

    memset(&var_sctpAssocRemPrimAddr, 0, sizeof(var_sctpAssocRemPrimAddr));
    var_sctpAssocRemPrimAddr.type = ASN_OCTET_STR;
    var_sctpAssocRemPrimAddr.next_variable = &var_sctpAssocId;
    snmp_set_var_value(&var_sctpAssocRemPrimAddr,
                       (u_char *) & entry->sctpAssocRemPrimAddr,
                       entry->sctpAssocRemPrimAddr_len);

    memset(&var_sctpAssocId, 0, sizeof(var_sctpAssocId));
    var_sctpAssocId.type = ASN_UNSIGNED;
    var_sctpAssocId.next_variable = NULL;
    snmp_set_var_value(&var_sctpAssocId, (u_char *) & entry->sctpAssocId,
                       sizeof(entry->sctpAssocId));

    /*
     * convert it 
     */
    err =
        build_oid_noalloc(entry->oid_index.oids, entry->oid_index.len,
                          &entry->oid_index.len, NULL, 0,
                          &var_sctpAssocRemPrimAddrType);
    if (err)
        snmp_log(LOG_ERR, "error %d converting index to oid\n", err);

    /*
     * release any memory allocated during the conversion 
     */
    snmp_reset_var_buffers(&var_sctpAssocRemPrimAddrType);

    return err;
}

void
sctpLookupRemPrimIPAddrTable_entry_copy(sctpLookupRemPrimIPAddrTable_entry
                                        * from,
                                        sctpLookupRemPrimIPAddrTable_entry
                                        * to)
{
    memcpy(to, from, sizeof(sctpLookupRemPrimIPAddrTable_entry));
    to->oid_index.oids = to->oid_tmp;
}


void
sctpLookupRemPrimIPAddrTable_entry_free(sctpLookupRemPrimIPAddrTable_entry
                                        * entry)
{
    SNMP_FREE(entry);
}

netsnmp_container *
sctpLookupRemPrimIPAddrTable_get_container(void)
{
    return sctpLookupRemPrimIPAddrTable_container;
}


static void
sctpLookupRemPrimIPAddrTable_entry_clear(void *what, void *magic)
{
    sctpLookupRemPrimIPAddrTable_entry_free(what);
}

void
sctpLookupRemPrimIPAddrTable_container_clear(netsnmp_container *container)
{
    CONTAINER_CLEAR(container, sctpLookupRemPrimIPAddrTable_entry_clear,
                    NULL);
}
