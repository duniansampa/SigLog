#ifndef ALL_HANDLERS_H
#define ALL_HANDLERS_H

#ifdef __cplusplus
extern          "C" {
#endif

#include <siglog/agent/instance.h>
#include <siglog/agent/baby_steps.h>
#include <siglog/agent/scalar.h>
#include <siglog/agent/scalar_group.h>
#include <siglog/agent/watcher.h>
#include <siglog/agent/multiplexer.h>
#include <siglog/agent/null.h>
#include <siglog/agent/debug_handler.h>
#include <siglog/agent/cache_handler.h>
#include <siglog/agent/old_api.h>
#include <siglog/agent/read_only.h>
#include <siglog/agent/row_merge.h>
#include <siglog/agent/serialize.h>
#include <siglog/agent/bulk_to_next.h>
#include <siglog/agent/mode_end_call.h>
/*
 * #include <siglog/agent/set_helper.h> 
 */
#include <siglog/agent/table.h>
#include <siglog/agent/table_data.h>
#include <siglog/agent/table_dataset.h>
#include <siglog/agent/table_tdata.h>
#include <siglog/agent/table_iterator.h>
#include <siglog/agent/table_container.h>
#include <siglog/agent/table_array.h> 

#include <siglog/agent/mfd.h>
#include <siglog/agent/snmp_get_statistic.h>


void            netsnmp_init_helpers(void);

#ifdef __cplusplus
}
#endif
#endif                          /* ALL_HANDLERS_H */
