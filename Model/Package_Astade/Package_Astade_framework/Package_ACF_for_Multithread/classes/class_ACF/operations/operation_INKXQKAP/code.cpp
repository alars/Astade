//~~ void cancelAll(ACF_MessageReceiver* Destination) [ACF] ~~

while (sem_wait(&myQueueSemaphore))
    ;

for (unsigned int i = 0; i < scheduledTimeouts; i++)
{
    if (my_Timeouts[i].Destination == Destination)
    {
        my_Timeouts[i].Destination = 0;
        break;
    }
}

for (unsigned int i = 0; i < my_Messages.size(); i++)
{
    if (my_Messages[i].Destination == Destination)
    {
        my_Messages[i].Destination = 0;
        break;
    }
}

sem_post(&myQueueSemaphore);