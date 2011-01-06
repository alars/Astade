//~~ void setEastWestYellowRed(ACF_Message* event) [crossroadController] ~~
ACF_sendMessage(MessageReceiver(), east, getYellowRed, 0);
ACF_sendMessage(MessageReceiver(), west, getYellowRed, 0);