me->HandleFunction = aHandleFunction;
if (me->TraceOption)
{
    ACF_TRACE(ACF_runningMachine);
    ACF_TRACE(" (!) ");
    ACF_TRACE(me->Name);
    ACF_TRACE("\n");
}
