#ifdef _TRACE_

extern void trace2uml_driver_notify_constructor(char* objectName, void* objectID);
extern void trace2uml_driver_notify_destructor(char* objectName, void* objectID);
extern void trace2uml_driver_notify_function_call(char* objectName, char* functionName, void* objectID);
extern void trace2uml_driver_notify_return(void);

#define NOTIFY_CCONSTRUCTOR(a,b,c) trace2uml_driver_notify_constructor(c,a); 
#define NOTIFY_CDESTRUCTOR(a,b) trace2uml_driver_notify_destructor(c,a);
#define NOTIFY_CFUNCTION_CALL(a,b,c,d,e,f) trace2uml_driver_notify_function_call(c,d,a);
#define CRETURN(a) do {trace2uml_driver_notify_return();return(a);} while(0)
#define voidRETURN do {trace2uml_driver_notify_return();return;} while(0)

#endif