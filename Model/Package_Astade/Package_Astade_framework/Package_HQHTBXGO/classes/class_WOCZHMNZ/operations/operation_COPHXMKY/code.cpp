//~~ void handleMessage() [ACF] ~~
while (sem_wait(&myQueueSemaphore))
    ;

if (nextRead != nextWrite)
{
    (my_Messages[nextRead].Destination)->HandleFunction(my_Messages[nextRead].Destination, &my_Messages[nextRead]);

    ++nextRead;
    if (nextRead >= my_Messages.size())
        nextRead = 0;
}

sem_post(&myQueueSemaphore);