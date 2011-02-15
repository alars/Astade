//~~ int handleMessage() [ACF] ~~
ACF_checkTimeouts();

if (ACF_nextRead != ACF_nextWrite)
{
    if (((ACF_MessageReceiver*)ACF_myMessages[ACF_nextRead].Destination)->Name)
    {
		ACF_traceTimestamp();
        if (((ACF_MessageReceiver*)ACF_myMessages[ACF_nextRead].Source) && 
            ((ACF_MessageReceiver*)ACF_myMessages[ACF_nextRead].Source)->Name)
        {
            ACF_tracePtr(ACF_myMessages[ACF_nextRead].Source);
            ACF_trace(((ACF_MessageReceiver*)ACF_myMessages[ACF_nextRead].Source)->Name);
        }
        else
        {
            ACF_trace("~");
        }
        ACF_trace(" --> ");
        ACF_tracePtr(ACF_myMessages[ACF_nextRead].Destination);
        ACF_trace(((ACF_MessageReceiver*)ACF_myMessages[ACF_nextRead].Destination)->Name);
        ACF_trace(" ");
        ACF_trace(ACF_myMessages[ACF_nextRead].ID);
        ACF_trace("\n");    
    }
    
    ((ACF_MessageReceiver*)ACF_myMessages[ACF_nextRead].Destination)->HandleFunction(ACF_myMessages[ACF_nextRead].Destination, &ACF_myMessages[ACF_nextRead]);

    ++ACF_nextRead;
    if (ACF_nextRead >= ACF_MESSAGEQUEUESIZE)
        ACF_nextRead = 0;
        
    return 1;
}

return 0;
