//~~ ACF() [ACF] ~~
sem_init(&mySleepSemaphore, 0, 0);
sem_init(&myQueueSemaphore, 0, 1);

for (int i = 0; i<10; i++)
    my_Messages.push_back(ACF_Message());
    
lastTime = getTimeTick();