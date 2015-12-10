//~~ int isPortFree(uint16_t port) [tcp_impl] ~~
int i;

for (i = 0; i < TCP_MAX_COUNT; i++)
{
    if (tcp_impl_registered[i])
    {
        if (tcp_impl_registered[i]->SourcePort == port)
            CRETURN(0); // port is already registered
    }
}
CRETURN(1); // the port number is free