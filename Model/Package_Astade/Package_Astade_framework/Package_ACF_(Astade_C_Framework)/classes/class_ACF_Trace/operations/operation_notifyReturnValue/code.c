if (me->callType == ACF_FUNCTIONCALL)
{
    ACF_trace("< ");
	ACF_traceTimestamp();
    
    if (ret)
    {
    	ACF_trace(" ");
    	ACF_trace(ret);
    }
    ACF_trace("\n");	
}
else if (me->callType == ACF_SELFCALL)
{
    ACF_trace("< ");
	ACF_traceTimestamp();
    ACF_trace("\n");	
}
