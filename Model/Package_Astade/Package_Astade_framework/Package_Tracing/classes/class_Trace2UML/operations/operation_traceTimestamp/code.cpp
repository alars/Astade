//~~ void traceTimestamp() [Trace2UML] ~~
char buffer[30];
struct timeval time;
gettimeofday(&time, NULL);
snprintf(buffer, sizeof(buffer), "[%ld.%03ld - %ld] ", time.tv_sec, time.tv_usec / 1000, GETTHREAD);
ms_ofile << buffer;
