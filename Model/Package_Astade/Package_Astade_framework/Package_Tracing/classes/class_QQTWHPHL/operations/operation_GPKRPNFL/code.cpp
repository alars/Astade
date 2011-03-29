//~~ void traceTimestamp() [Trace2UML] ~~
char buffer[18];
struct timeval time;
gettimeofday(&time, NULL);
snprintf(buffer, sizeof(buffer), "[%ld.%03ld] ", time.tv_sec, time.tv_usec / 1000);
ms_ofile << buffer;
