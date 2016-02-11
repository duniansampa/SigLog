#ifdef UCD_COMPATIBLE

#include <siglog/net-snmp-config.h>
#include <siglog/types.h>
#include <siglog/library/snmp_impl.h>

#else

#error "Please update your headers or configure using --enable-ucd-snmp-compatibility"

#endif
