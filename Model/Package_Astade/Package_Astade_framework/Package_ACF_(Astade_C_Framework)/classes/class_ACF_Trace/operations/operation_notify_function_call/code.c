me->callType = ACF_FUNCTIONCALL;
me->callingID = ACF_Trace_runningID;
me->callingName = ACF_Trace_runningName;

ACF_Trace_runningID = objectID;
ACF_Trace_runningName = objectName;
 
ACF_traceTimestamp();
if (me->callingID)
    ACF_tracePtr(me->callingID);
ACF_trace(me->callingName);
ACF_trace(" ==> ");

if (objectID)
    ACF_tracePtr(objectID);
ACF_trace(objectName);

ACF_trace(" ");
ACF_trace(functionName); 
ACF_trace("()\n");
