#include <time.h>
#include <unistd.h>

#ifdef WIN32
    #define GETTHREAD GetCurrentThreadId()
#else
#include <sys/syscall.h>
    #define GETTHREAD syscall(SYS_gettid)
#endif

#include <sys/time.h>
