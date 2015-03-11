//~~ void testonly(const QString& port, const AQF_Message& event) [trigger_impl] ~~
Q_UNUSED(port);
Q_UNUSED(event);
AQF_sendMessage(myDest, AQF_Message(push));