//~~ void sendTimeoutMessage(ACF_MessageReceiver* Destination) [ACF] ~~

// We do not wait on the semaphore here, because it is
// already held by our only caller checkTimeouts()

checkMessageQueueSize();

my_Messages[nextWrite].Source = 0;
my_Messages[nextWrite].Destination = Destination;
my_Messages[nextWrite].ID = ACF_timeout;
my_Messages[nextWrite].Data = 0;
my_Messages[nextWrite].DataIncluded = false;

if (++nextWrite >= my_Messages.size())
	nextWrite = 0;
