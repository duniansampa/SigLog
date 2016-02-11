/*
 * gettimeofday() replacement for MSVC.
 */

#include <sigLogH/net-snmp-config.h>
#include <sigLogH/types.h>

#ifdef HAVE_SYS_TIMEB_H
# include <sys/timeb.h> /* _ftime() */
#endif
#if TIME_WITH_SYS_TIME
# include <sys/time.h>
# include <time.h>
#else
# if HAVE_SYS_TIME_H
#  include <sys/time.h>
# else
#  include <time.h>
# endif
#endif

#include <sigLogH/library/system.h>

int
gettimeofday(struct timeval *tv, struct timezone *tz)
{
    struct timeb   timebuffer;

    ftime(&timebuffer);
    tv->tv_usec = timebuffer.millitm * 1000;
    tv->tv_sec = (long)timebuffer.time;
    return (0);
}
