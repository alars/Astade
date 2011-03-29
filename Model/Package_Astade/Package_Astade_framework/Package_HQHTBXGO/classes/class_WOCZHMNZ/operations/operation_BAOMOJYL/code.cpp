//~~ void cancelTimeout(ACF_MessageReceiver* Destination) [ACF] ~~

printf("1\n");

while (sem_wait(&myQueueSemaphore))
    ;

printf("2\n");

if (scheduledTimeouts == 0)
{
    sem_post(&myQueueSemaphore);
    return;
}

printf("3\n");

int last = scheduledTimeouts - 1;

if (my_Timeouts[last].Destination == Destination) 
{
    --scheduledTimeouts;
    sem_post(&myQueueSemaphore);
    return;
}

printf("4\n");

for (int i = 0; i < last; i++)
{
    printf("5\n");

    if (my_Timeouts[i].Destination == Destination)
    {
    printf("6\n");

        my_Timeouts[i+1].Time += my_Timeouts[i].Time;
        memmove(&my_Timeouts[i], &my_Timeouts[i+1], sizeof(my_Timeouts[i]) * (last - i));
        --scheduledTimeouts;
        break;
    }
}

sem_post(&myQueueSemaphore);

printf("7\n");
