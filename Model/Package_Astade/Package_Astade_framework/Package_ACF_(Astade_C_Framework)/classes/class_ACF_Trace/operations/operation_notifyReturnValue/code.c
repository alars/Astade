if (me->callType == ACF_FUNCTIONCALL)
{
	ACF_traceTimestamp();
    if (me->callingID)
        ACF_tracePtr(me->callingID);
    ACF_trace(me->callingName);
    ACF_trace(" <== ");
    
    if (ACF_Trace_runningID)
        ACF_tracePtr(ACF_Trace_runningID);
    ACF_trace(ACF_Trace_runningName);
    if (ret)
    {
    	ACF_trace(" ");
    	ACF_trace(ret);
    }
    ACF_trace("\n");	
}
else if (me->callType == ACF_SELFCALL)
{
	ACF_traceTimestamp();
    if (ACF_Trace_runningID)
        ACF_tracePtr(ACF_Trace_runningID);
    ACF_trace(ACF_Trace_runningName);
    ACF_trace(" <== ");
    
    if (ACF_Trace_runningID)
        ACF_tracePtr(ACF_Trace_runningID);
    ACF_trace(ACF_Trace_runningName);
    ACF_trace("\n");	
}

ACF_Trace_runningID = me->callingID;
ACF_Trace_runningName = me->callingName;
