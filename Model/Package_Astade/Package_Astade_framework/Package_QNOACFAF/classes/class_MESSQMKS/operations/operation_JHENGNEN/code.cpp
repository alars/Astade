//~~ void cancelTimeout() [AQF_MessageReceiver] ~~
if (m_timerID != 0)
{
    killTimer(m_timerID);
    m_timerID = 0;
}