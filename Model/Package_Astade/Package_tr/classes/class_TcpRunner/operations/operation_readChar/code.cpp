//~~ std::string readChar(unsigned int mSecTimeout) [TcpRunner] ~~
char c[10];

int n = read(mFD,c,1);

if (n==1)
{
    RETURN(std::string(c,1));
} else {
    RETURN(std::string());
}