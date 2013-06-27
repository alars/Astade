//~~ void notify_destructor(void* objectID, int traceLevel, const char* objectName) [ACF_Trace] ~~
me->callType = ACF_DESTRUCTOR;

ACF_trace("- ");
ACF_traceTimestamp();

if (objectID)
    ACF_tracePtr(objectID);
ACF_trace(objectName);

ACF_trace("\n");
