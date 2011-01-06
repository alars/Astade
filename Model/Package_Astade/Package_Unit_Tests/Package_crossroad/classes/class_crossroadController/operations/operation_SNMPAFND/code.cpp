//~~ void setAllRed(ACF_Message* event) [crossroadController] ~~
ACF_sendMessage(MessageReceiver(), north, getRed, 0);
ACF_sendMessage(MessageReceiver(), south, getRed, 0);
ACF_sendMessage(MessageReceiver(), east, getRed, 0);
ACF_sendMessage(MessageReceiver(), west, getRed, 0);