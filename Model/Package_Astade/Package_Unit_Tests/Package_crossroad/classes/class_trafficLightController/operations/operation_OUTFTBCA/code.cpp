//~~ void setRed(ACF_Message* event) [trafficLightController] ~~
ACF_sendMessage(MessageReceiver(), redControl, getOn, 0);
ACF_sendMessage(MessageReceiver(), yellowControl, getOff, 0);
ACF_sendMessage(MessageReceiver(), greenControl, getOff, 0);
