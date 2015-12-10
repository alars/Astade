//~~ void unregister() [tcp_impl] ~~
int i;

// just to make sure, the port is set to zero
me->SourcePort = 0;

for (i = 0; i < TCP_MAX_COUNT; i++)
{
    if (tcp_impl_registered[i] == me)
        tcp_impl_registered[i] = 0; // remove me
}