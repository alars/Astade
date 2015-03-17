//~~ void timerEvent(QTimerEvent * event) [AQF_MessageReceiver] ~~
Q_UNUSED(event);
cancelTimeout(); // we want one shot

if (m_tracefile)
{
    const char *realname = getName(this);

    if (_semaphore)
        while (sem_wait(_semaphore));
        
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

    if (_semaphore)
        sem_post(_semaphore);
        
    TakeEvent(0,AQF_Message(AQF_timeout));

    if (_semaphore)
        while (sem_wait(_semaphore));
        
    *m_tracefile 
        << "<"
        << "["
        << QDateTime().currentMSecsSinceEpoch() 
        << "]{" 
        << QThread::currentThread() 
        << "}" 
        << std::endl;
        
    if (_semaphore)
        sem_post(_semaphore);
} else {
    TakeEvent(0,AQF_Message(AQF_timeout));
}