//~~ void setNorthSouthYellowRed(ACF_Message* event) [crossroadController] ~~
ACF_sendMessage(MessageReceiver(), north, getYellowRed, 0);
ACF_sendMessage(MessageReceiver(), south, getYellowRed, 0);