//~~ void handleMessage() [ACF] ~~
while (sem_wait(&myQueueSemaphore))
    ;

if (nextRead != nextWrite)
{
    size_t handleThis = nextRead;
    
    ++nextRead;
    if (nextRead >= my_Messages.size())
        nextRead = 0;
        
    sem_post(&myQueueSemaphore);
    (my_Messages[handleThis].Destination)->HandleFunction(my_Messages[handleThis].Destination, &my_Messages[handleThis]);
}
else
{
    sem_post(&myQueueSemaphore);
}