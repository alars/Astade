//~~ void sendInternalMessage(ACF_MessageReceiver* Source, ACF_MessageReceiver* Destination, const char* ID, void* Data) [ACF] ~~

ACF_myMessages[ACF_nextWrite].Source = Source;
ACF_myMessages[ACF_nextWrite].Destination = Destination;
ACF_myMessages[ACF_nextWrite].ID = ID;
ACF_myMessages[ACF_nextWrite].Data = Data;

if (++ACF_nextWrite >= ACF_MESSAGEQUEUESIZE)
	ACF_nextWrite = 0;
