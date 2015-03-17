//~~ void trace_receive(const AQF_MessageReceiver* port, const AQF_Message& theEvent) [AQF_MessageReceiver] ~~
if (m_tracefile)
{
    int status1;
    char *myname = abi::__cxa_demangle(typeid(*this).name(), 0, 0, &status1);
    int status2;
    char *destname = abi::__cxa_demangle(typeid(*port).name(), 0, 0, &status2);
    
    
    *m_tracefile << (void*)port << ":" << destname << " --> "
                 << (void*)this << ":" << myname << " "
                 << theEvent.getID() << std::endl;


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

    TakeEvent(port, theEvent);
        
    *m_tracefile 
        << "<"
        << "["
        << QDateTime().currentMSecsSinceEpoch() 
        << "]{" 
        << QThread::currentThread() 
        << "}" 
        << std::endl;

} else {
    TakeEvent(port, theEvent);
}
