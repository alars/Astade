//~~ void setYellow(ACF_Message* event) [trafficLightController] ~~
ACF_sendMessage(MessageReceiver(), redControl, getOff, 0);
ACF_sendMessage(MessageReceiver(), yellowControl, getOn, 0);
ACF_sendMessage(MessageReceiver(), greenControl, getOff, 0);
