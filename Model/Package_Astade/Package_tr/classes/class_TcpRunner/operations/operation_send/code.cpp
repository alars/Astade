//~~ void send(const std::string& data) [TcpRunner] ~~
RunnerInterface::send(data);

int n = write(mFD,data.c_str(),strlen(data.c_str()));

if (n < 0) {
    fprintf(stderr, "Failed to Write the socket\n");
    exit(4);
}