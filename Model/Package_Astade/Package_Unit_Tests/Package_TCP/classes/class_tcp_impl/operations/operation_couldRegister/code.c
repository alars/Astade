//~~ int couldRegister(ACF_Message* event) [tcp_impl] ~~
uint16_t port = (intptr_t)event->Data;
int res = tcp_impl_register(me, port);
CRETURN(res);