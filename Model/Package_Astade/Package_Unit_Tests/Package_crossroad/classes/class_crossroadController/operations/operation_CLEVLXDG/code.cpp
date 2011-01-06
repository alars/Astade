//~~ void setNorthSouthGreen(ACF_Message* event) [crossroadController] ~~
ACF_sendMessage(MessageReceiver(), north, getGreen, 0);
ACF_sendMessage(MessageReceiver(), south, getGreen, 0);