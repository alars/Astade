#define ACF_scheduleTimeout ACF::staticScheduleTimeout
#define ACF_Trace_notify_constructor(x,y,LEVEL,CLASS) Trace2UML NOTIFY_FUNCTION_CALL_Helper(0,LEVEL,&MessageReceiver_base,CLASS,"");
#define ACF_Trace_notify_destructor(x,y,LEVEL,CLASS) Trace2UML NOTIFY_FUNCTION_CALL_Helper(2,LEVEL,&MessageReceiver_base,CLASS)
#define ACF_Trace_notify_function_call(x,y,LEVEL,CLASS,FUNCTION) NOTIFY_FUNCTION_CALL(&MessageReceiver_base,LEVEL,CLASS,FUNCTION,"","")
#define ACF_Trace_notify_self_call(a,b,c,d,e) Trace2UML NOTIFY_FUNCTION_CALL_Helper(3,c,me,d,"","TakeEvent");
#define ACF_Trace_notify_state(a,b,c,d) Trace2UML::notify_state(b,&MessageReceiver_base,c,d)

// This trace entries are not needed in a C++ environment and are declared empty
#define ACF_Trace int __attribute__((unused)) 
#define ACF_Trace_notifyReturn(x)

#include <semaphore.h>