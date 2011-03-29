//~~ bool interuptableSleep() [ACF] ~~
int sleeptime = getShortestTimer();

if (sleeptime == -1)
{
    return(sem_wait(&mySleepSemaphore) != 0);
}
else
{
    struct timespec ts;
    struct timeval time;
    gettimeofday(&time, NULL);

    ts.tv_sec = time.tv_sec;
    ts.tv_nsec = time.tv_usec * 1000;

    ts.tv_sec  +=  sleeptime / 1000;
    ts.tv_nsec += (sleeptime % 1000) * 1000000;
    while (ts.tv_nsec >= 1000000000)
    {
        ts.tv_nsec -= 1000000000;
        ts.tv_sec++;
    }
    return(sem_timedwait(&mySleepSemaphore, &ts) != 0);
}