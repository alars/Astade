//~~ void trace_initialize_begin() [AQF_MessageReceiver] ~~
if (m_tracefile)
{
    if (_semaphore)
        while (sem_wait(_semaphore));
        
    *m_tracefile 
        << ">"
        << "["
        << QDateTime().currentMSecsSinceEpoch() 
        << "]{" 
        << QThread::currentThread() 
        << "}" 
        << (void*)this 
        << ":" 
        << getName(this) 
        << " Initialize()" 
        << std::endl;
        
    if (_semaphore)
        sem_post(_semaphore);
}
