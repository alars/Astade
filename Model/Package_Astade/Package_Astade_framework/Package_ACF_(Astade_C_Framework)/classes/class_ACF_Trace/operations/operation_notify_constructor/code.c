//~~ void notify_constructor(const void* objectID, int traceLevel, const char* objectName) [ACF_Trace] ~~
me->callType = ACF_CONSTRUCTOR;

ACF_trace("+ ");
ACF_traceTimestamp();

if (objectID)
    ACF_tracePtr(objectID);
ACF_trace(objectName);

ACF_trace("\n");
