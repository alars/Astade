//~~ bool interuptableSleep(unsigned int milliSec) [ACF] ~~
struct timespec ts;
struct timeval time;
gettimeofday(&time, NULL);

  ts.tv_sec = time.tv_sec;
  ts.tv_nsec = time.tv_usec * 1000;

  ts.tv_sec  +=  milliSec / 1000;
  ts.tv_nsec += (milliSec % 1000) * 1000000;
  while (ts.tv_nsec >= 1000000000)
  {
    ts.tv_nsec -= 1000000000;
    ts.tv_sec++;
  }
  return(sem_timedwait(&mySleepSemaphore, &ts) != 0);
