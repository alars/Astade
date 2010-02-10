#define NOTIFY_FUNCTION_CALL(a,b,c,d,e,f)   \
    ACF_Trace ACF_LOCALTRACEHELPER;         \
    ACF_Trace_notify_function_call(&ACF_LOCALTRACEHELPER,a,b,c,d);

#define NOTIFY_CONSTRUCTOR(a,b,c)           \
    ACF_Trace ACF_LOCALTRACEHELPER;         \
    ACF_Trace_notify_constructor(&ACF_LOCALTRACEHELPER,me,a,b);

#define NOTIFY_DESTRUCTOR(a,b)              \
    ACF_Trace ACF_LOCALTRACEHELPER;         \
    ACF_Trace_notify_destructor(&ACF_LOCALTRACEHELPER,me,a,b);

#define RETURN(a) do {ACF_Trace_notifyReturn(&ACF_LOCALTRACEHELPER); return(a);} while(0);

#define voidRETURN do {ACF_Trace_notifyReturn(&ACF_LOCALTRACEHELPER); return;} while(0);

