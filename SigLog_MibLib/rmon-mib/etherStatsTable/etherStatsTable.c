/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 14170 $ of $ 
 *
 * $Id:$
 */
/** \page MFD helper for etherStatsTable
 *
 * \section intro Introduction
 * Introductory text.
 *
 */
/*
 * standard Net-SNMP includes 
 */
#include <siglog/net-snmp-config.h>
#include <siglog/net-snmp-includes.h>
#include <siglog/agent/net-snmp-agent-includes.h>

/*
 * include our parent header 
 */
#include "etherStatsTable.h"

#include <siglog/agent/mib_modules.h>

#include "etherStatsTable_interface.h"

oid             etherStatsTable_oid[] = { ETHERSTATSTABLE_OID };
int             etherStatsTable_oid_size = OID_LENGTH(etherStatsTable_oid);

etherStatsTable_registration etherStatsTable_user_context;
static etherStatsTable_registration *etherStatsTable_user_context_p;

void            initialize_table_etherStatsTable(void);
void            shutdown_table_etherStatsTable(void);


/**
 * Initializes the etherStatsTable module
 */
void
init_etherStatsTable(void)
{
    DEBUGMSGTL(("verbose:etherStatsTable:init_etherStatsTable",
                "called\n"));

    /*
     * TODO:300:o: Perform etherStatsTable one-time module initialization.
     */

    /*
     * here we initialize all the tables we're planning on supporting
     */
    if (should_init("etherStatsTable"))
        initialize_table_etherStatsTable();

}                               /* init_etherStatsTable */

/**
 * Shut-down the etherStatsTable module (agent is exiting)
 */
void
shutdown_etherStatsTable(void)
{
    if (should_init("etherStatsTable"))
        shutdown_table_etherStatsTable();

}

/**
 * Initialize the table etherStatsTable 
 *    (Define its contents and how it's structured)
 */
void
initialize_table_etherStatsTable(void)
{
    u_long          flags;

    DEBUGMSGTL(("verbose:etherStatsTable:initialize_table_etherStatsTable",
                "called\n"));

    /*
     * TODO:301:o: Perform etherStatsTable one-time table initialization.
     */

    /*
     * TODO:302:o: |->Initialize etherStatsTable user context
     * if you'd like to pass in a pointer to some data for this
     * table, allocate or set it up here.
     */
    /*
     * a netsnmp_data_list is a simple way to store void pointers. A simple
     * string token is used to add, find or remove pointers.
     */
    etherStatsTable_user_context_p
	= netsnmp_create_data_list("etherStatsTable", NULL, NULL);

    /*
     * No support for any flags yet, but in the future you would
     * set any flags here.
     */
    flags = 0;

    /*
     * call interface initialization code
     */
    _etherStatsTable_initialize_interface
	(etherStatsTable_user_context_p, flags);
}                               /* initialize_table_etherStatsTable */

/**
 * Shutdown the table etherStatsTable 
 */
void
shutdown_table_etherStatsTable(void)
{
    /*
     * call interface shutdown code
     */
    _etherStatsTable_shutdown_interface(etherStatsTable_user_context_p);
    netsnmp_free_all_list_data(etherStatsTable_user_context_p);
    etherStatsTable_user_context_p = NULL;
}

/**
 * extra context initialization (eg default values)
 *
 * @param rowreq_ctx    : row request context
 * @param user_init_ctx : void pointer for user (parameter to rowreq_ctx_allocate)
 *
 * @retval MFD_SUCCESS  : no errors
 * @retval MFD_ERROR    : error (context allocate will fail)
 */
int
etherStatsTable_rowreq_ctx_init(etherStatsTable_rowreq_ctx * rowreq_ctx,
                                void *user_init_ctx)
{
    DEBUGMSGTL(("verbose:etherStatsTable:etherStatsTable_rowreq_ctx_init",
                "called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:210:o: |-> Perform extra etherStatsTable rowreq initialization. (eg DEFVALS)
     */

    return MFD_SUCCESS;
}                               /* etherStatsTable_rowreq_ctx_init */

/**
 * extra context cleanup
 *
 */
void
etherStatsTable_rowreq_ctx_cleanup(etherStatsTable_rowreq_ctx * rowreq_ctx)
{
    DEBUGMSGTL(("verbose:etherStatsTable:etherStatsTable_rowreq_ctx_cleanup", "called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:211:o: |-> Perform extra etherStatsTable rowreq cleanup.
     */
}                               /* etherStatsTable_rowreq_ctx_cleanup */

/**
 * pre-request callback
 *
 *
 * @retval MFD_SUCCESS              : success.
 * @retval MFD_ERROR                : other error
 */
int
etherStatsTable_pre_request(etherStatsTable_registration * user_context)
{
    DEBUGMSGTL(("verbose:etherStatsTable:etherStatsTable_pre_request",
                "called\n"));

    /*
     * TODO:510:o: Perform etherStatsTable pre-request actions.
     */

    return MFD_SUCCESS;
}                               /* etherStatsTable_pre_request */

/**
 * post-request callback
 *
 * Note:
 *   New rows have been inserted into the container, and
 *   deleted rows have been removed from the container and
 *   released.
 *
 * @param user_context
 * @param rc : MFD_SUCCESS if all requests succeeded
 *
 * @retval MFD_SUCCESS : success.
 * @retval MFD_ERROR   : other error (ignored)
 */
int
etherStatsTable_post_request(etherStatsTable_registration * user_context,
                             int rc)
{
    DEBUGMSGTL(("verbose:etherStatsTable:etherStatsTable_post_request",
                "called\n"));

    /*
     * TODO:511:o: Perform etherStatsTable post-request actions.
     */

    /*
     * check to set if any rows were changed.
     */
    if (etherStatsTable_dirty_get()) {
        /*
         * check if request was successful. If so, this would be
         * a good place to save data to its persistent store.
         */
        if (MFD_SUCCESS == rc) {
            /*
             * save changed rows, if you haven't already
             */
        }

        etherStatsTable_dirty_set(0);   /* clear table dirty flag */
    }

    return MFD_SUCCESS;
}                               /* etherStatsTable_post_request */


/** @{ */