/* Define all Hardware dependend stuff here */

/** The number of messages, which can be queued inside the message queue */
#define ACF_MESSAGEQUEUESIZE 20

/** The number of timeouts, which can be queued inside the timer queue */
#define ACF_MAXTIMEOUTS 20

/** This macro is used for tracing. 
    it gets a pointer to NULL terminated char array
    and should be aple to place the characters (the trace) somwhere.
    if you don't use tracing you can leave this macro empty */
#include "stdio.h"
#define ACF_TRACE(x) printf("%s",x);

