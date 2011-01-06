//~~ void setEastWestYellow(ACF_Message* event) [crossroadController] ~~
ACF_sendMessage(MessageReceiver(), east, getYellow, 0);
ACF_sendMessage(MessageReceiver(), west, getYellow, 0);