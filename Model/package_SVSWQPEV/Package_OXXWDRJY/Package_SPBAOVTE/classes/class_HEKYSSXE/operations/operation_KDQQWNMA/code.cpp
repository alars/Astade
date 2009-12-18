ACF_checkTimeouts();

if (ACF_nextRead != ACF_nextWrite)
{
    if (((ACF_MessageReceiver*)(ACF_myMessages[ACF_nextRead].Destination))->TraceOption)
    {
        if ((ACF_MessageReceiver*)ACF_myMessages[ACF_nextRead].Source)
        {
            ACF_trace(((ACF_MessageReceiver*)(ACF_myMessages[ACF_nextRead].Source))->Name);
        }
        else
        {
            ACF_trace((char*)"~");
        }
        ACF_trace((char*)" --> ");
        ACF_trace(((ACF_MessageReceiver*)(ACF_myMessages[ACF_nextRead].Destination))->Name);
        ACF_trace((char*)" ");
        ACF_trace(ACF_myMessages[ACF_nextRead].ID);
        ACF_trace((char*)"\n");    
    }

    ++ACF_nextRead;
    if (ACF_nextRead >= ACF_MESSAGEQUEUESIZE)
        ACF_nextRead = 0;
}
