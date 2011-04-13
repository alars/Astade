//~~ void handleMessage() [ACF] ~~
while (sem_wait(&myQueueSemaphore))
    ;

if (nextRead != nextWrite)
{
    size_t handleThis = nextRead;
    
    if (my_Messages[handleThis].Destination) // might be NULL, when the destination was deleted
    {
        if (my_Messages[handleThis].Destination->Name)
        {
            if (my_Messages[handleThis].Source)
            {
                Trace2UML::notify_message_received(
                                                    my_Messages[handleThis].Source,
                                                    my_Messages[handleThis].Source->Name,
                                                    my_Messages[handleThis].Destination,
                                                    my_Messages[handleThis].Destination->Name,
                                                    my_Messages[handleThis].ID
                                                  );
            }
            else
            {
                Trace2UML::notify_message_received(
                                                    0,0,
                                                    my_Messages[handleThis].Destination,
                                                    my_Messages[handleThis].Destination->Name,
                                                    my_Messages[handleThis].ID
                                                  );
            }
        }
        
        ++nextRead;
        if (nextRead >= my_Messages.size())
            nextRead = 0;
            
        sem_post(&myQueueSemaphore);
        (my_Messages[handleThis].Destination)->HandleFunction(my_Messages[handleThis].Destination, &my_Messages[handleThis]);
    }
    else
    {
        ++nextRead;
        if (nextRead >= my_Messages.size())
            nextRead = 0;
            
        sem_post(&myQueueSemaphore);
    }
}    
else
{
    sem_post(&myQueueSemaphore);
}