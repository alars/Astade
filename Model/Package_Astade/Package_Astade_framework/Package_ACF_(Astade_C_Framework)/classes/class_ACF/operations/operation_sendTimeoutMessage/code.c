//~~ void sendTimeoutMessage(ACF_MessageReceiver* Destination) [ACF] ~~

if (ACF_nextRead == 0)
    ACF_nextRead = ACF_MESSAGEQUEUESIZE - 1;
else
    ACF_nextRead--;

ACF_myMessages[ACF_nextRead].Source = 0;
ACF_myMessages[ACF_nextRead].Destination = Destination;
ACF_myMessages[ACF_nextRead].ID = ACF_timeout;
ACF_myMessages[ACF_nextRead].Data = 0;
