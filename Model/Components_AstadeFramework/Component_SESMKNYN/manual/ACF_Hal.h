/* Define all Hardware dependend stuff here */

/** The number of messages, which can be queued inside the message queue */
#define ACF_MESSAGEQUEUESIZE 20

/** The number of timeouts, which can be queued inside the timer queue */
#define ACF_MAXTIMEOUTS 20

/** This function is used for tracing. 
    it gets a pointer to NULL terminated char array
    and should be able to place the characters (the trace) somewhere.
    if you don't use tracing you can leave this function empty */
#include "stdio.h"
inline void ACF_trace(const char* x)
{
    printf("%s",x);
}

/** This function returns an incresing unsigned integer counter.
    The framework uses it to implement all timeouts.
    in a Microcontroller system you normally would use
    a hardware timer for this. */
#include <sys/time.h>
inline unsigned int ACF_getTimeTick(void)
{
    timeval time;
    gettimeofday(&time,0);
    return ((time.tv_sec*1000)+(time.tv_usec/1000)); //I want milliseconds
}

/** This function is used to swich off all hardware interrupts. 
    The framework uses this, whenever queuing messages
    so it is possible to send messages from an interrupt routine*/
inline void ACF_interrupts_off()
{
}

/** This function is used to swich on all hardware interrupts. 
    The framework uses this, whenever queuing messages
    so it is possible to send messages from an interrupt routine*/
inline void ACF_interrupts_on()
{
}

