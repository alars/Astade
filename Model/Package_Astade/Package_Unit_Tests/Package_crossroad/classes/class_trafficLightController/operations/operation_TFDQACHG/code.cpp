//~~ void setGreen(ACF_Message* event) [trafficLightController] ~~
ACF_sendMessage(MessageReceiver(), redControl, getOff, 0);
ACF_sendMessage(MessageReceiver(), yellowControl, getOff, 0);
ACF_sendMessage(MessageReceiver(), greenControl, getOn, 0);
