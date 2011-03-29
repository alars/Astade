#define ACF_scheduleTimeout ACF::scheduleTimeout
#define ACF_Trace_notify_constructor(x,y,LEVEL,CLASS) NOTIFY_CONSTRUCTOR(LEVEL,CLASS,"")
#define ACF_Trace_notify_destructor(x,y,LEVEL,CLASS) NOTIFY_DESTRUCTOR(LEVEL,CLASS)
#define ACF_Trace_notify_function_call(x,y,LEVEL,CLASS,FUNCTION) NOTIFY_FUNCTION_CALL(this,LEVEL,CLASS,FUNCTION,"","")

// This trace entries are not needed in a C++ environment and are declared empty
#define ACF_Trace int __attribute__((unused)) 
#define ACF_Trace_notifyReturn(x)
#define ACF_Trace_notify_self_call(a,b,c,d,e)
#define ACF_Trace_notify_state(a,b,s,d)