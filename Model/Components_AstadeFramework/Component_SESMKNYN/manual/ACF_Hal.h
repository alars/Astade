/* Define all Hardware dependend stuff here */

/** The number of messages, which can be queued inside the message queue */
#define ACF_MESSAGEQUEUESIZE 20

/** The number of timeouts, which can be queued inside the timer queue */
#define ACF_MAXTIMEOUTS 20

/** This macro is used for tracing. 
    it gets a pointer to NULL terminated char array
    and should be able to place the characters (the trace) somewhere.
    if you don't use tracing you can leave this macro empty */
#include "stdio.h"
#define ACF_TRACE(x) printf("%s",x);

/** This function returns an incresing unsigned integer counter.
    The framework uses it to implement all timeouts.
    in a Microcontroller system you normally would use
    a hardware timer for this. */
#include <sys/time.h>
inline unsigned int ACF_GETTIMETICK(void)
{
    unsigned long long time;
    gettimeofday((timeval*)&time,0);
    return time/1000; //I want milliseconds
}



