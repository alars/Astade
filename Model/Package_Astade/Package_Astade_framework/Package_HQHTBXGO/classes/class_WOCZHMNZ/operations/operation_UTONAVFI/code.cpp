//~~ unsigned int getTimeout(ACF_MessageReceiver* Source) [ACF] ~~

while (sem_wait(&myQueueSemaphore))
    ;

unsigned int timeSum = 0;
unsigned int index = 0;

while (index < scheduledTimeouts)
{
    timeSum += my_Timeouts[index].Time;
    if (my_Timeouts[index].Destination == Source)
    {
        sem_post(&myQueueSemaphore);
        RETURN(timeSum);
    }
    ++index;
}

sem_post(&myQueueSemaphore);
RETURN(0);