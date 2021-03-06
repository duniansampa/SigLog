/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.create-dataset.conf,v 5.2 2002/07/17 14:41:53 dts12 Exp $
 */

#include <siglog/net-snmp-config.h>
#include <siglog/net-snmp-features.h>
#include <siglog/net-snmp-includes.h>
#include <siglog/agent/net-snmp-agent-includes.h>
#include "mteEventNotificationTable.h"

netsnmp_feature_require(table_dataset)
netsnmp_feature_require(table_set_multi_add_default_row)

netsnmp_table_data_set *mteEventNotif_table_set;


/** Initialize the mteEventNotificationTable table by defining its contents and how it's structured */
void
initialize_table_mteEventNotificationTable(void)
{
    static oid      mteEventNotificationTable_oid[] =
        { 1, 3, 6, 1, 2, 1, 88, 1, 4, 3 };
    size_t          mteEventNotificationTable_oid_len =
        OID_LENGTH(mteEventNotificationTable_oid);

    /*
     * create the table structure itself 
     */
    mteEventNotif_table_set = netsnmp_create_table_data_set("mteEventNotificationTable");

    /*
     * comment this out or delete if you don't support creation of new rows 
     */
    mteEventNotif_table_set->allow_creation = 1;

    /***************************************************
     * Adding indexes
     */
    DEBUGMSGTL(("initialize_table_mteEventNotificationTable",
                "adding indexes to table mteEventNotificationTable\n"));
    netsnmp_table_set_add_indexes(mteEventNotif_table_set,
                                  /* index: mteOwner */
                                  ASN_OCTET_STR,
                                  /* index: mteEventName */
                                  ASN_PRIV_IMPLIED_OCTET_STR,
                                  0);

    DEBUGMSGTL(("initialize_table_mteEventNotificationTable",
                "adding column types to table mteEventNotificationTable\n"));
    netsnmp_table_set_multi_add_default_row(mteEventNotif_table_set,
                                            COLUMN_MTEEVENTNOTIFICATION,
                                            ASN_OBJECT_ID, 1, NULL, 0,
                                            COLUMN_MTEEVENTNOTIFICATIONOBJECTSOWNER,
                                            ASN_OCTET_STR, 1, NULL, 0,
                                            COLUMN_MTEEVENTNOTIFICATIONOBJECTS,
                                            ASN_OCTET_STR, 1, NULL, 0, 0);

    /* keep index values around for comparisons later */
    mteEventNotif_table_set->table->store_indexes = 1;
    /*
     * registering the table with the master agent 
     */
    /*
     * note: if you don't need a subhandler to deal with any aspects
     * of the request, change mteEventNotificationTable_handler to "NULL" 
     */
#ifndef NETSNMP_NO_WRITE_SUPPORT
    netsnmp_register_table_data_set(netsnmp_create_handler_registration
                                    ("mteEventNotificationTable",
                                     mteEventNotificationTable_handler,
                                     mteEventNotificationTable_oid,
                                     mteEventNotificationTable_oid_len,
                                     HANDLER_CAN_RWRITE), mteEventNotif_table_set, NULL);
#else /* !NETSNMP_NO_WRITE_SUPPORT */
    netsnmp_register_table_data_set(netsnmp_create_handler_registration
                                    ("mteEventNotificationTable",
                                     mteEventNotificationTable_handler,
                                     mteEventNotificationTable_oid,
                                     mteEventNotificationTable_oid_len,
                                     HANDLER_CAN_RONLY), mteEventNotif_table_set, NULL);
#endif /* !NETSNMP_NO_WRITE_SUPPORT */
}

/** Initializes the mteEventNotificationTable module */
void
init_mteEventNotificationTable(void)
{

    /*
     * here we initialize all the tables we're planning on supporting 
     */
    initialize_table_mteEventNotificationTable();
}

/** handles requests for the mteEventNotificationTable table, if anything else needs to be done */
int
mteEventNotificationTable_handler(netsnmp_mib_handler *handler,
                                  netsnmp_handler_registration *reginfo,
                                  netsnmp_agent_request_info *reqinfo,
                                  netsnmp_request_info *requests)
{
    /*
     * perform anything here that you need to do.  The requests have
     * already been processed by the master table_dataset handler, but
     * this gives you chance to act on the request in some other way
     * if need be. 
     */
    return SNMP_ERR_NOERROR;
}
