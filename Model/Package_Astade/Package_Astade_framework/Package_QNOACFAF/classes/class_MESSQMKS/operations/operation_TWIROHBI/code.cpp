//~~ void timerEvent(QTimerEvent * event) [AQF_MessageReceiver] ~~
Q_UNUSED(event);
cancelTimeout(); // we want one shot
TakeEvent(QString(),AQF_Message(AQF_timeout));