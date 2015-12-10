//~~ void clearTCB(ACF_Message* event) [tcp_impl] ~~
tcp_impl_unregister(me);
me->SourcePort = 0;
me->DestinationPort = 0;