me->HandleFunction = aHandleFunction;
if (me->TraceOption)
{
    ACF_trace(ACF_runningMachine);
    ACF_trace((char*)" (!) ");
    ACF_trace(me->Name);
    ACF_trace((char*)"\n");
}
