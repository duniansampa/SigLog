#ifdef UCD_COMPATIBLE

#include <siglog/version.h>

#define VersionInfo NetSnmpVersionInfo

#else

#error "Please update your headers or configure using --enable-ucd-snmp-compatibility"

#endif
