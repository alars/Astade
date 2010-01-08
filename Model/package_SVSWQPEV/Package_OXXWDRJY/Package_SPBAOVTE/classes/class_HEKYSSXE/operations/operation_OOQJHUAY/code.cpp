ACF_interrupts_off();
if (Destination->Name && Source)
{
    ACF_trace(Source->Name);
    ACF_trace((char*)" >-- ");
    ACF_trace(Destination->Name);
    ACF_trace((char*)" ");
    ACF_trace(ID);
    ACF_trace((char*)"\n");    
}

ACF_myMessages[ACF_nextWrite].Source = Source;
ACF_myMessages[ACF_nextWrite].Destination = Destination;
ACF_myMessages[ACF_nextWrite].ID = ID;
ACF_myMessages[ACF_nextWrite].Data = Data;

++ACF_nextWrite;
if (ACF_nextWrite >= ACF_MESSAGEQUEUESIZE)
    ACF_nextWrite = 0;
ACF_interrupts_on();
