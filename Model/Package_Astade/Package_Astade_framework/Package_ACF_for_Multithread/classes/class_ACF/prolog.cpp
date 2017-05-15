#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#ifdef WIN32
#include <windows.h>
#define sleep(x) Sleep(x);
#endif
const char*	ACF_timeout = "ACF_timeout";
