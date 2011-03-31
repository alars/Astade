//~~ bool interuptableSleep() [ACF] ~~
int sleeptime = getShortestTimer();

if (sleeptime == 0)
{
    RETURN(true);
}

if ((sleeptime == -1) || (sleeptime > 500))
{
    sleeptime = 50; // We don't sleep longer than 500
}

struct timespec ts;
struct timeval time;
gettimeofday(&time, NULL);

ts.tv_sec = time.tv_sec;
ts.tv_nsec = time.tv_usec * 1000;

// ts.tv_sec  +=  sleeptime / 1000; // not needed, because sleeptime is maximum 500
ts.tv_nsec += (sleeptime % 1000) * 1000000;
while (ts.tv_nsec >= 1000000000)
{
    ts.tv_nsec -= 1000000000;
    ts.tv_sec++;
}
RETURN(sem_timedwait(&mySleepSemaphore, &ts) != 0);