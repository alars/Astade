me->HandleFunction = aHandleFunction;
if (me->Name)
{
    ACF_trace((char*)"~ (!) ");
    ACF_tracePtr(me);
    ACF_trace(me->Name);
    ACF_trace((char*)"\n");
}
