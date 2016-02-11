/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 14170 $ of $
 *
 * $Id:$
 */
#ifndef IPIFSTATSTABLE_H
#define IPIFSTATSTABLE_H

#ifdef __cplusplus
extern          "C" {
#endif


/** @addtogroup misc misc: Miscellaneous routines
 *
 * @{
 */
#include <siglog/library/asn1.h>
#include <siglog/data_access/ipstats.h>
#include <siglog/data_access/systemstats.h>

    /*
     * other required module components 
     */
    /* *INDENT-OFF*  */
config_require(ip-mib/ipIfStatsTable/ipIfStatsTable_interface)
config_require(ip-mib/ipIfStatsTable/ipIfStatsTable_data_access)
config_require(ip-mib/ipIfStatsTable/ipIfStatsTable_data_get)
    /* *INDENT-ON*  */

    /*
     * OID and column number definitions for ipIfStatsTable 
     */
#include "ipIfStatsTable_oids.h"

    /*
     * enum definions 
     */
#include "ipIfStatsTable_enums.h"

    /*
     *********************************************************************
     * function declarations
     */
    void            init_ipIfStatsTable(void);
    void            shutdown_ipIfStatsTable(void);

    /*
     *********************************************************************
     * Table declarations
     */
/**********************************************************************
 **********************************************************************
 ***
 *** Table ipIfStatsTable
 ***
 **********************************************************************
 **********************************************************************/
    /*
     * IP-MIB::ipIfStatsTable is subid 3 of ipTrafficStats.
     * Its status is Current.
     * OID: .1.3.6.1.2.1.4.31.3, length: 9
     */
    /*
     *********************************************************************
     * When you register your mib, you get to provide a generic
     * pointer that will be passed back to you for most of the
     * functions calls.
     *
     * TODO:100:r: Review all context structures
     */
    /*
     * TODO:101:o: |-> Review ipIfStatsTable registration context.
     */
    typedef netsnmp_data_list ipIfStatsTable_registration;

/**********************************************************************/
    /*
     * TODO:110:r: |-> Review ipIfStatsTable data context structure.
     * This structure is used to represent the data for ipIfStatsTable.
     */
    typedef netsnmp_systemstats_entry ipIfStatsTable_data;


    /*
     * TODO:120:r: |-> Review ipIfStatsTable mib index.
     * This structure is used to represent the index for ipIfStatsTable.
     */
    typedef struct ipIfStatsTable_mib_index_s {

        /*
         * ipIfStatsIPVersion(1)/InetVersion/ASN_INTEGER/long(u_long)//l/a/w/E/r/d/h
         */
        u_long          ipIfStatsIPVersion;

        /*
         * ipIfStatsIfIndex(2)/InterfaceIndex/ASN_INTEGER/long(long)//l/a/w/e/R/d/H
         */
        long            ipIfStatsIfIndex;


    } ipIfStatsTable_mib_index;

    /*
     * TODO:121:r: |   |-> Review ipIfStatsTable max index length.
     * If you KNOW that your indexes will never exceed a certain
     * length, update this macro to that length.
     */
#define MAX_ipIfStatsTable_IDX_LEN     2


    /*
     *********************************************************************
     * TODO:130:o: |-> Review ipIfStatsTable Row request (rowreq) context.
     * When your functions are called, you will be passed a
     * ipIfStatsTable_rowreq_ctx pointer.
     */
    typedef struct ipIfStatsTable_rowreq_ctx_s {

    /** this must be first for container compare to work */
        netsnmp_index   oid_idx;
        oid             oid_tmp[MAX_ipIfStatsTable_IDX_LEN];

        ipIfStatsTable_mib_index tbl_idx;

        ipIfStatsTable_data *data;

        /*
         * flags per row. Currently, the first (lower) 8 bits are reserved
         * for the user. See mfd.h for other flags.
         */
        u_int           rowreq_flags;

        /*
         * TODO:131:o: |   |-> Add useful data to ipIfStatsTable rowreq context.
         */
        char            known_missing;
        uint32_t        ipIfStatsDiscontinuityTime;
        uint32_t        ipIfStatsRefreshRate;

        /*
         * storage for future expansion
         */
        netsnmp_data_list *ipIfStatsTable_data_list;

    } ipIfStatsTable_rowreq_ctx;

    typedef struct ipIfStatsTable_ref_rowreq_ctx_s {
        ipIfStatsTable_rowreq_ctx *rowreq_ctx;
    } ipIfStatsTable_ref_rowreq_ctx;

    /*
     *********************************************************************
     * function prototypes
     */
    int             ipIfStatsTable_pre_request(ipIfStatsTable_registration
                                               * user_context);
    int             ipIfStatsTable_post_request(ipIfStatsTable_registration
                                                * user_context, int rc);

    int            
        ipIfStatsTable_rowreq_ctx_init(ipIfStatsTable_rowreq_ctx *
                                       rowreq_ctx, void *user_init_ctx);
    void           
        ipIfStatsTable_rowreq_ctx_cleanup(ipIfStatsTable_rowreq_ctx *
                                          rowreq_ctx);

    ipIfStatsTable_data *ipIfStatsTable_allocate_data(void);
    void            ipIfStatsTable_release_data(ipIfStatsTable_data *
                                                data);


    ipIfStatsTable_rowreq_ctx
        *ipIfStatsTable_row_find_by_mib_index(ipIfStatsTable_mib_index *
                                              mib_idx);

    extern const oid      ipIfStatsTable_oid[];
    extern const int      ipIfStatsTable_oid_size;


#include "ipIfStatsTable_interface.h"
#include "ipIfStatsTable_data_access.h"
#include "ipIfStatsTable_data_get.h"

    /*
     * DUMMY markers, ignore
     *
     * TODO:099:x: *************************************************************
     * TODO:199:x: *************************************************************
     * TODO:299:x: *************************************************************
     * TODO:399:x: *************************************************************
     * TODO:499:x: *************************************************************
     */

#ifdef __cplusplus
}
#endif
#endif                          /* IPIFSTATSTABLE_H */
/** @} */
