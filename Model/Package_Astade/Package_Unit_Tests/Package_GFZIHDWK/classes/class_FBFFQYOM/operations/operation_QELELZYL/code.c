//~~ void testonly(ACF_Message* event) [trigger_impl] ~~
ACF_sendMessage((ACF_MessageReceiver*)me, me->myDest, push, 0);
