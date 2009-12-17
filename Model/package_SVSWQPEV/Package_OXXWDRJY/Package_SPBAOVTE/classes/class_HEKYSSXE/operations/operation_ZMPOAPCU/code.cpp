if (Destination->TraceOption && Source)
{
    ACF_TRACE(Source->Name);
    ACF_TRACE(" >-- ");
    ACF_TRACE(Destination->Name);
    ACF_TRACE(" ");
    ACF_TRACE(Name);
    ACF_TRACE("\n");    
}

ACF_myMessages[ACF_nextWrite].Source = Source;
ACF_myMessages[ACF_nextWrite].Destination = Destination;
ACF_myMessages[ACF_nextWrite].ID = ID;
ACF_myMessages[ACF_nextWrite].Data = Data;
ACF_myMessages[ACF_nextWrite].Name = Name;

++ACF_nextWrite;
if (ACF_nextWrite >= ACF_MESSAGEQUEUESIZE)
    ACF_nextWrite = 0;