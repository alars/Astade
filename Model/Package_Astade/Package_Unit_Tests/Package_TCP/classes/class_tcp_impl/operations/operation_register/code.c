//~~ int register(uint16_t port) [tcp_impl] ~~
int i;

// just to make sure, the port is set to zero, if something fails
me->SourcePort = 0;

for (i = 0; i < TCP_MAX_COUNT; i++)
{
    if (tcp_impl_registered[i])
    {
        if (tcp_impl_registered[i] == me)
            CRETURN(0); // I'am already registered
        if (tcp_impl_registered[i]->SourcePort == port)
            CRETURN(0); // port is already registered
    }
}
for (i = 0; i < TCP_MAX_COUNT; i++)
{
    if (tcp_impl_registered[i] == 0)
    {
        tcp_impl_registered[i] = me;
        me->SourcePort = port;
        CRETURN(1);
    }
}
CRETURN(0); // no free table entry