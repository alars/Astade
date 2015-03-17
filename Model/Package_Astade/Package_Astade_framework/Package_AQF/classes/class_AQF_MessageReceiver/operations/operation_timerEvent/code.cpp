//~~ void timerEvent(QTimerEvent * event) [AQF_MessageReceiver] ~~
Q_UNUSED(event);
cancelTimeout(); // we want one shot

if (m_tracefile)
{
    int status;
    char *realname = abi::__cxa_demangle(typeid(*this).name(), 0, 0, &status);

    *m_tracefile 
        << "["
        << QDateTime().currentMSecsSinceEpoch() 
        << "]{" 
        << QThread::currentThread() 
        << "}" 
        << (void*)this 
        << ":" 
        << realname 
        << " ==> "
        << (void*)this 
        << ":" 
        << realname 
        << " TIMEOUT " 
        << std::endl;

    TakeEvent(0,AQF_Message(AQF_timeout));

    *m_tracefile 
        << "<"
        << "["
        << QDateTime().currentMSecsSinceEpoch() 
        << "]{" 
        << QThread::currentThread() 
        << "}" 
        << std::endl;
} else {
    TakeEvent(0,AQF_Message(AQF_timeout));
}