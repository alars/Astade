//~~ uint16_t findFreePort() [tcp_impl] ~~
while (1)
{
    tcp_impl_lastUsedPortNumber--;
    if (tcp_impl_lastUsedPortNumber <= 20000)
        tcp_impl_lastUsedPortNumber = 65030;
    if (tcp_impl_isPortFree(tcp_impl_lastUsedPortNumber))
        CRETURN(tcp_impl_lastUsedPortNumber);
}