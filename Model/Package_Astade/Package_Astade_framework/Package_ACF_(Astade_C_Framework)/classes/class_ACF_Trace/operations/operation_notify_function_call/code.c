me->callType = ACF_FUNCTIONCALL;
 
ACF_trace("> ");
ACF_traceTimestamp();

if (objectID)
    ACF_tracePtr(objectID);
ACF_trace(objectName);

ACF_trace(" ");
ACF_trace(functionName); 
ACF_trace("()\n");
