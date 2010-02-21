#ifdef __cplusplus
}

#include <cstdio>
#include <string>

class ACF_return_helper
{
public:	
	ACF_Trace trace_data; 
	char buffer[25]; // if it gets longer, it takes too much room in Trace2UML
	ACF_return_helper() { snprintf(buffer,sizeof(buffer)," "); }
	~ACF_return_helper() { ACF_Trace_notifyReturnValue(&trace_data,buffer); }
	void setRetval(const char* x) { snprintf(buffer,sizeof(buffer),"%s",x); }
	void setRetval(int x) { snprintf(buffer,sizeof(buffer),"%d",x); }
	void setRetval(unsigned int x) { snprintf(buffer,sizeof(buffer),"%u",x); }
	void setRetval(short x) { snprintf(buffer,sizeof(buffer),"%hd",x); }
	void setRetval(unsigned short x) { snprintf(buffer,sizeof(buffer),"%hu",x); }
	void setRetval(long x) { snprintf(buffer,sizeof(buffer),"%ld",x); }
	void setRetval(unsigned long x) { snprintf(buffer,sizeof(buffer),"%lu",x); }
	void setRetval(char x) { snprintf(buffer,sizeof(buffer),"%hhu",x); }
	void setRetval(signed char x) { snprintf(buffer,sizeof(buffer),"%hhd",x); }
	void setRetval(unsigned char x) { snprintf(buffer,sizeof(buffer),"%hhu",x); }
	void setRetval(double x) { snprintf(buffer,sizeof(buffer),"%g",x); }
	void setRetval(bool x) { snprintf(buffer,sizeof(buffer),(x)?"true":"false"); }
	void setRetval(const void* x) { snprintf(buffer,sizeof(buffer),"%p",x); }
	void setRetval(const std::string& x) { snprintf(buffer,sizeof(buffer),"%s",x.c_str()); }
};

#define NOTIFY_FUNCTION_CALL(a,b,c,d,e)     \
	ACF_return_helper ACF_LOCALTRACEHELPER;         \
 	ACF_Trace_notify_function_call(&ACF_LOCALTRACEHELPER.trace_data,this,a,b,c);

#define NOTIFY_CONSTRUCTOR(a,b,c)           \
	ACF_return_helper ACF_LOCALTRACEHELPER;         \
	ACF_Trace_notify_constructor(&ACF_LOCALTRACEHELPER.trace_data,this,a,b);

#define NOTIFY_DESTRUCTOR(a,b)              \
	ACF_return_helper ACF_LOCALTRACEHELPER;         \
	ACF_Trace_notify_destructor(&ACF_LOCALTRACEHELPER.trace_data,this,a,b);

#define NOTIFY_RETURN_VALUE(a)  ACF_LOCALTRACEHELPER.setRetval(a);

#define RETURN(a) do { ACF_LOCALTRACEHELPER.setRetval(a); return(a); } while(0)	

extern "C" {
#endif

#define NOTIFY_CFUNCTION_CALL(a,b,c,d,e,f)  \
	ACF_Trace ACF_LOCALTRACEHELPER;         \
	ACF_Trace_notify_function_call(&ACF_LOCALTRACEHELPER,a,b,c,d);

#define NOTIFY_CCONSTRUCTOR(a,b,c)          \
	ACF_Trace ACF_LOCALTRACEHELPER;         \
	ACF_Trace_notify_constructor(&ACF_LOCALTRACEHELPER,me,a,b);

#define NOTIFY_CDESTRUCTOR(a,b)             \
	ACF_Trace ACF_LOCALTRACEHELPER;         \
	ACF_Trace_notify_destructor(&ACF_LOCALTRACEHELPER,me,a,b);

#define CRETURN(a) do { ACF_Trace_notifyReturn(&ACF_LOCALTRACEHELPER); return(a); } while(0);

#define voidRETURN do { ACF_Trace_notifyReturn(&ACF_LOCALTRACEHELPER); return; } while(0);
