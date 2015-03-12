//~~ void testonly(const QString& port, const AQF_Message& event) [trigger_impl] ~~
Q_UNUSED(port);
Q_UNUSED(event);
sendMessage(myDest, AQF_Message(push));