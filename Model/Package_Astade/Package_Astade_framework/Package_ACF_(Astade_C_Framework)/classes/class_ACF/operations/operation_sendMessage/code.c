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

ACF_myMessages[ACF_nextWrite].Source = Source;
ACF_myMessages[ACF_nextWrite].Destination = Destination;
ACF_myMessages[ACF_nextWrite].ID = ID;
ACF_myMessages[ACF_nextWrite].Data = Data;

++ACF_nextWrite;
if (ACF_nextWrite >= ACF_MESSAGEQUEUESIZE)
    ACF_nextWrite = 0;
ACF_interrupts_on();
