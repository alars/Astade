me->HandleFunction = aHandleFunction;
if (me->Name)
{
    snprintf(me->me_text,sizeof(me->me_text),"%p",me);
    ACF_trace((char*)"~ (!) ");
    ACF_trace(me->me_text);
    ACF_trace((char*)":");
    ACF_trace(me->Name);
    ACF_trace((char*)"\n");
}
