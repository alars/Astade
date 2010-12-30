/* Define all hardware dependent stuff here */

/** The number of messages which can be queued inside the message queue */
#define ACF_MESSAGEQUEUESIZE 20

 /** The number of timeouts which can be queued inside the timer queue */
#define ACF_MAXTIMEOUTS 20

#ifdef __cplusplus
extern "C" {
#endif

/** This function is for initialising the environment */
void ACF_init(void);

/** This function returns an increasing unsigned integer counter.
    The framework uses it to implement all timeouts.
    In a microcontroller system you normally would use
    a hardware timer for this. */
unsigned int ACF_getTimeTick(void);

/** This function waits for the specified number of milliseconds.
    It is called when the scheduler determines that the system is idle.
    In a microcontroller system you might simply wait for the next
    interrupt (or leave the function empty).
    @param ms The number of milliseconds to wait or -1 if no timer is active */
void ACF_wait(int ms);

/** This function is used to swich off all hardware interrupts. 
    The framework uses this whenever queuing messages
    so it is possible to send messages from an interrupt routine */
void ACF_interrupts_off(void);

/** This function is used to swich on all hardware interrupts. 
    The framework uses this whenever queuing messages
    so it is possible to send messages from an interrupt routine */
void ACF_interrupts_on(void);

/** This function is used for tracing. 
    It should be able to write the trace somewhere.
    If you don't use tracing you can leave this function empty.
    @param string A C-string to append to the trace */
void ACF_trace(const char* string);

/** This function is used for tracing pointers.
    @param ptr A pointer */
void ACF_tracePtr(const void* ptr);

/** This function is used for tracing timestamps.  */
void ACF_traceTimestamp(void);

#ifdef __cplusplus
}
#endif
