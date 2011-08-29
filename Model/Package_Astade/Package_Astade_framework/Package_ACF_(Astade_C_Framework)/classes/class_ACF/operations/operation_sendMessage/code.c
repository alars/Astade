//~~ void sendMessage(ACF_MessageReceiver* Source, ACF_MessageReceiver* Destination, const char* ID, void* Data) [ACF] ~~

ACF_interrupts_off();

if (Destination->Name && Source)
{
	ACF_traceTimestamp();
    if (Source->Name)
    {
        ACF_tracePtr(Source);
        ACF_trace(Source->Name);
    }
    else
        ACF_trace("~");
        
    ACF_trace(" >-- ");
    ACF_tracePtr(Destination);
    ACF_trace(Destination->Name);
    ACF_trace(" ");
    ACF_trace(ID);
    ACF_trace("\n");    
}

int wasEmpty = ACF_nextRead == ACF_nextWrite;
ACF_sendInternalMessage(Source, Destination, ID, Data);
if (wasEmpty)
    ACF_wakeup();

ACF_interrupts_on();
