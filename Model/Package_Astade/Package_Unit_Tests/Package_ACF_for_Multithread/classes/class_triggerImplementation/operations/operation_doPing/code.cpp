//~~ void doPing(ACF_Message* event) [triggerImplementation] ~~
ACF_sendMessage(MessageReceiver(), toPingPong, tick, 0);