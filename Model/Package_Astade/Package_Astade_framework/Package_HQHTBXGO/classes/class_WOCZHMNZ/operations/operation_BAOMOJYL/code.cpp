//~~ void cancelTimeout(ACF_MessageReceiver* Destination) [ACF] ~~

while (sem_wait(&myQueueSemaphore))
    ;

if (scheduledTimeouts == 0)
{
    sem_post(&myQueueSemaphore);
    return;
}

int last = scheduledTimeouts - 1;

if (my_Timeouts[last].Destination == Destination) 
{
    --scheduledTimeouts;
    sem_post(&myQueueSemaphore);
    return;
}

for (int i = 0; i < last; i++)
{
    if (my_Timeouts[i].Destination == Destination)
    {
        my_Timeouts[i+1].Time += my_Timeouts[i].Time;
        memmove(&my_Timeouts[i], &my_Timeouts[i+1], sizeof(my_Timeouts[i]) * (last - i));
        --scheduledTimeouts;
        break;
    }
}

sem_post(&myQueueSemaphore);