//~~ int couldRegister(ACF_Message* event) [tcp_impl] ~~
//int port = (long)event->Data;
int res = tcp_impl_register((ACF_MessageReceiver*)me);
CRETURN(res);