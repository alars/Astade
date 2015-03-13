//~~ void testonly(const AQF_MessageReceiver* port, const AQF_Message& event) [trigger_impl] ~~
Q_UNUSED(port);
Q_UNUSED(event);
sendMessage(myDest, AQF_Message(push));