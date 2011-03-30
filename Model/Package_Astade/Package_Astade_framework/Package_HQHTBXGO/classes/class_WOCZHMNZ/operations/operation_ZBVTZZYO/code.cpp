//~~ void sendMessage(ACF_MessageReceiver* Source, ACF_MessageReceiver* Destination, const char* ID, void* Data) [ACF] ~~
while (sem_wait(&myQueueSemaphore))
    ;

checkMessageQueueSize();

my_Messages[nextWrite].Source = Source;
my_Messages[nextWrite].Destination = Destination;
my_Messages[nextWrite].ID = ID;
my_Messages[nextWrite].Data = Data;

if ((Destination->Name) && (Source))
    Trace2UML::notify_message_sent(Source, Source->Name, Destination, Destination->Name, ID);

if (nextRead == nextWrite) // queue is empty, so we possible should wakeup the thread
{
    ++nextWrite;
    if (nextWrite >= my_Messages.size())
        nextWrite = 0;

    interruptSleep();
}
else
{
    ++nextWrite;
    if (nextWrite >= my_Messages.size())
        nextWrite = 0;
}

sem_post(&myQueueSemaphore);
