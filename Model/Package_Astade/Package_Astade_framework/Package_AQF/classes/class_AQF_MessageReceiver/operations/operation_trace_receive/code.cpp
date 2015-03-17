//~~ void trace_receive(const AQF_MessageReceiver* port, const AQF_Message& theEvent) [AQF_MessageReceiver] ~~
if (m_tracefile)
{
    const char *myname = getName(this);
    const char *destname = "~";
    
    if (_semaphore)
        while (sem_wait(_semaphore));
        
    if (port) 
    {
        destname = getName(port);
    
        *m_tracefile << (void*)port << ":" << destname << " --> "
                     << (void*)this << ":" << myname << " "
                     << theEvent.getID() << std::endl;

    } else {
        *m_tracefile << destname << " --> "
                     << (void*)this << ":" << myname << " "
                     << theEvent.getID() << std::endl;
    }
    
    *m_tracefile 
        << "["
        << QDateTime().currentMSecsSinceEpoch() 
        << "]{" 
        << QThread::currentThread() 
        << "}" 
        << (void*)this 
        << ":" 
        << myname 
        << " ==> "
        << (void*)this 
        << ":" 
        << myname 
        << " TakeEvent()"
        << std::endl;
        
    if (_semaphore)
        sem_post(_semaphore);

    TakeEvent(port, theEvent);
        
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
    TakeEvent(port, theEvent);
}
