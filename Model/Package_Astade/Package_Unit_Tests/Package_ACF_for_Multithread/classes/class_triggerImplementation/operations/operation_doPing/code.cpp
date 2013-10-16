//~~ void doPing(ACF_Message* event) [triggerImplementation] ~~
ACF_MessageData* TestData = new ACF_MessageData;
ACF_sendMessage(MessageReceiver(), toPingPong, tick, *TestData);