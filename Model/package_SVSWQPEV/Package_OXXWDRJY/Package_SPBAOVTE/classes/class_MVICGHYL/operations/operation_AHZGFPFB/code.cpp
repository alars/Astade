if (me->callType == ACF_FUNCTIONCALL)
{
    if (me->callingID)
        ACF_tracePtr(me->callingID);
    ACF_trace(me->callingName);
    ACF_trace(" <== ");
    
    if (ACF_Trace_runningID)
        ACF_tracePtr(ACF_Trace_runningID);
    ACF_trace(ACF_Trace_runningName);
    ACF_trace("\n");	
}

if (me->callType == ACF_SELFCALL)
{
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
