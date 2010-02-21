#ifdef __cplusplus
}
#include <stdio.h>
#include <string>
	class ACF_return_helper
	{
	public:	
		ACF_Trace trace_data; 
		const char* ret;
		char buffer[25]; // if it gets longer, it takes to much room in Trace2UML
		ACF_return_helper(){ret = " ";};
		~ACF_return_helper(){ACF_Trace_notifyReturnValue(&trace_data, ret);};
		void setRetval(const char* x){ret=buffer; snprintf(buffer,sizeof(buffer),"%s",x);};
		void setRetval(int x){ret=buffer; snprintf(buffer,sizeof(buffer),"%d",x);};
		void setRetval(unsigned int x){ret=buffer; snprintf(buffer,sizeof(buffer),"%u",x);};
		void setRetval(unsigned long x){ret=buffer; snprintf(buffer,sizeof(buffer),"%lu",x);};
		void setRetval(unsigned char x){ret=buffer; snprintf(buffer,sizeof(buffer),"%hu",x);};
		void setRetval(bool x){if (x) ret="true"; else ret="false";};
		void setRetval(const void* x){ret=buffer; snprintf(buffer,sizeof(buffer),"0x%p",x);};
		void setRetval(const std::string& x){ret=buffer; snprintf(buffer,sizeof(buffer),"%s",x.c_str());};
	};
extern "C" {
#endif

#define NOTIFY_FUNCTION_CALL(a,b,c,d,e)     \
	ACF_return_helper ACF_LOCALTRACEHELPER;         \
 	ACF_Trace_notify_function_call(&ACF_LOCALTRACEHELPER.trace_data,this,a,b,c);

#define NOTIFY_CONSTRUCTOR(a,b,c)           \
	ACF_return_helper ACF_LOCALTRACEHELPER;         \
	ACF_Trace_notify_constructor(&ACF_LOCALTRACEHELPER.trace_data,this,a,b);

#define NOTIFY_DESTRUCTOR(a,b)              \
	ACF_return_helper ACF_LOCALTRACEHELPER;         \
	ACF_Trace_notify_destructor(&ACF_LOCALTRACEHELPER.trace_data,this,a,b);

#define NOTIFY_CFUNCTION_CALL(a,b,c,d,e,f)  \
	ACF_Trace ACF_LOCALTRACEHELPER;         \
	ACF_Trace_notify_function_call(&ACF_LOCALTRACEHELPER,a,b,c,d);

#define NOTIFY_CCONSTRUCTOR(a,b,c)          \
	ACF_Trace ACF_LOCALTRACEHELPER;         \
	ACF_Trace_notify_constructor(&ACF_LOCALTRACEHELPER,me,a,b);

#define NOTIFY_CDESTRUCTOR(a,b)             \
	ACF_Trace ACF_LOCALTRACEHELPER;         \
	ACF_Trace_notify_destructor(&ACF_LOCALTRACEHELPER,me,a,b);

#define RETURN(a) do { ACF_LOCALTRACEHELPER.setRetval(a); return(a);} while(0)	
					 
#define CRETURN(a) do {ACF_Trace_notifyReturn(&ACF_LOCALTRACEHELPER); return(a);} while(0)

#define voidRETURN do {ACF_Trace_notifyReturn(&ACF_LOCALTRACEHELPER); return;} while(0)

