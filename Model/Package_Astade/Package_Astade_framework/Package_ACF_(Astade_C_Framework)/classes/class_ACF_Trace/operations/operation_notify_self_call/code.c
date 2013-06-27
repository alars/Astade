me->callType = ACF_SELFCALL;
 
ACF_traceTimestamp();
ACF_tracePtr(objectID);
ACF_trace(objectName);
ACF_trace(" ==> ");

ACF_tracePtr(objectID);
ACF_trace(objectName);

ACF_trace(" ");
ACF_trace(functionName); 
ACF_trace("()\n");
