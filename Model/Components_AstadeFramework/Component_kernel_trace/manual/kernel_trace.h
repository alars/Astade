#ifndef KERNEL_TRACE_H
#define KERNEL_TRACE_H

extern void trcDriver_notify_function_call(int traceLevel, char* objectName, char* functionName, void* objectID);
extern void trcDriver_notifyReturn(void);
extern void trcDriver_notify_constructor(int traceLevel, char* objectName, void* objectID);
extern void trcDriver_notify_destructor(int traceLevel, char* objectName, void* objectID);

#define NOTIFY_FUNCTION_CALL(a,b,c,d,e,f) trcDriver_notify_function_call(b,c,d,a);
#define RETURN(a) do {trcDriver_notifyReturn(); return(a);} while(0);
#define voidRETURN do {trcDriver_notifyReturn(); return;} while(0);
#define NOTIFY_CONSTRUCTOR(a,b,c) trcDriver_notify_constructor(a,b,me);
#define NOTIFY_DESTRUCTOR(a,b) trcDriver_notify_destructor(a,b,me);

#endif
