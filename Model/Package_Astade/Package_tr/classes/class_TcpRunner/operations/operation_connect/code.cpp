//~~ void connect(const char* host, unsigned int port) [TcpRunner] ~~
mFD = socket(AF_INET, SOCK_STREAM, 0);

if (mFD < 0) {
    fprintf(stderr,"ERROR, could not get a socket file descriptor\n");
    exit(1);
}

#if 0
struct hostent *hoststruct;     /* host information */

struct in_addr h_addr;          /* internet address */

if ((hoststruct = gethostbyname(host)) == NULL) {
  fprintf(stderr, "(mini) nslookup failed on '%s'\n", host);
  exit(2);
}
#endif

struct sockaddr_in server;

/* Construct the server sockaddr_in structure */
memset(&server, 0, sizeof(server));           /* Clear struct */
server.sin_family = AF_INET;                  /* Internet/IP */
server.sin_addr.s_addr = inet_addr(host);     /* IP address */
server.sin_port = htons(port);                /* server port */

/* Establish connection */
if (::connect(mFD, (struct sockaddr *) &server, sizeof(server)) < 0) {
  fprintf(stderr, "Failed to connect to server:'%s', port:%d\n",host,port);
  exit(2);
}
