//~~ void timerEvent(QTimerEvent * event) [AQF_MessageReceiver] ~~
Q_UNUSED(event);
cancelTimeout(); // we want one shot
TakeEvent(0,AQF_Message(AQF_timeout));
