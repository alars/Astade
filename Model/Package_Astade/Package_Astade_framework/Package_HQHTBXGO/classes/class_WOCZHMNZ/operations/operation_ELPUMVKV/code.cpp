//~~ void sendTimeoutMessage(ACF_MessageReceiver* Destination) [ACF] ~~
// We do not have a semaphore here, because its only called from checkTimeouts()

checkMessageQueueSize();

if (nextRead==0)
    nextRead = my_Messages.size() - 1;
else
    nextRead--;

my_Messages[nextRead].Source = 0;
my_Messages[nextRead].Destination = Destination;
my_Messages[nextRead].ID = ACF_timeout;
my_Messages[nextRead].Data = 0;
