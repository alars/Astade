//~~ void setEastWestGreen(ACF_Message* event) [crossroadController] ~~
ACF_sendMessage(MessageReceiver(), east, getGreen, 0);
ACF_sendMessage(MessageReceiver(), west, getGreen, 0);