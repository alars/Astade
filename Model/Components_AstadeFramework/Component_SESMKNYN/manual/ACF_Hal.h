/* Define all hardware dependend stuff here */

/** The number of messages, which can be queued inside the message queue */
#define ACF_MESSAGEQUEUESIZE 20

 /** The number of timeouts, which can be queued inside the timer queue */
#define ACF_MAXTIMEOUTS 20

#ifdef __cplusplus
extern "C" {
#endif

/** This function is for initializing the environment */
extern void ACF_init(void);

/** This function is used for tracing. 
    it gets a pointer to NULL terminated char array
    and should be able to place the characters (the trace) somewhere.
    if you don't use tracing you can leave this function empty */
extern void ACF_trace(const char* x);

/** This function returns an incresing unsigned integer counter.
    The framework uses it to implement all timeouts.
    in a Microcontroller system you normally would use
    a hardware timer for this. */
extern unsigned int ACF_getTimeTick(void);

/** This function is used to swich off all hardware interrupts. 
    The framework uses this, whenever queuing messages
    so it is possible to send messages from an interrupt routine*/
extern void ACF_interrupts_off();

/** This function is used to swich on all hardware interrupts. 
    The framework uses this, whenever queuing messages
    so it is possible to send messages from an interrupt routine*/
extern void ACF_interrupts_on();

#ifdef __cplusplus
}
#endif

