//~~ void setNorthSouthYellow(ACF_Message* event) [crossroadController] ~~
ACF_sendMessage(MessageReceiver(), north, getYellow, 0);
ACF_sendMessage(MessageReceiver(), south, getYellow, 0);