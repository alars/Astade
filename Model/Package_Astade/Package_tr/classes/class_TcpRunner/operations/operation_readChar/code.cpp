//~~ std::string readChar(unsigned int mSecTimeout) [TcpRunner] ~~
char c[10];

struct timeval selTimeout;
selTimeout.tv_sec = mSecTimeout / 1000;           /* timeout (secs.) */
selTimeout.tv_usec = (mSecTimeout % 1000) * 1000; /* 0 microseconds */
fd_set readSet;
FD_ZERO(&readSet);
FD_SET(mFD+1, &readSet);  //tcp socket

int numReady = select(1, &readSet, NULL, NULL, &selTimeout);
if (numReady <= 0)
{
    RETURN(std::string());
}

int n = read(mFD,c,1);

if (n==1)
{
    RETURN(std::string(c,1));
} else {
    RETURN(std::string());
}