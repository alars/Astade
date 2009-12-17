//ACF_checkTimeouts();
if (ACF_nextRead != ACF_nextWrite)
{
    if (((ACF_MessageReceiver*)(ACF_myMessages[ACF_nextRead].Destination))->TraceOption)
    {
        if ((ACF_MessageReceiver*)ACF_myMessages[ACF_nextRead].Source)
        {
            ACF_TRACE(((ACF_MessageReceiver*)(ACF_myMessages[ACF_nextRead].Source))->Name);
        }
        else
        {
            ACF_TRACE("~");
        }
        ACF_TRACE(" --> ");
        ACF_TRACE(((ACF_MessageReceiver*)(ACF_myMessages[ACF_nextRead].Destination))->Name);
        ACF_TRACE(" ");
        ACF_TRACE(ACF_myMessages[ACF_nextRead].Name);
        ACF_TRACE("\n");    
    }

    ++ACF_nextRead;
    if (ACF_nextRead >= ACF_MESSAGEQUEUESIZE)
        ACF_nextRead = 0;
}