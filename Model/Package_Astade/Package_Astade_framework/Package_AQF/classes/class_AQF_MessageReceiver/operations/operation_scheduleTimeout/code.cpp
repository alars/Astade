//~~ void scheduleTimeout(int timeout_mSec) [AQF_MessageReceiver] ~~
cancelTimeout(); // just to be sure;
m_timerID = startTimer(timeout_mSec);
