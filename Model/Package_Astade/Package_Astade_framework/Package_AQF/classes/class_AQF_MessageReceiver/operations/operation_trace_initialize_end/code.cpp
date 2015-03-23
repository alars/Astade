//~~ void trace_initialize_end() [AQF_MessageReceiver] ~~
if (m_tracefile)
{
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
}
