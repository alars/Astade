//~~ unsigned int getTimeTick() [RunnerInterface] ~~
struct timeval time;
gettimeofday(&time, NULL);
RETURN(time.tv_sec * 1000 + time.tv_usec / 1000); //I want milliseconds
