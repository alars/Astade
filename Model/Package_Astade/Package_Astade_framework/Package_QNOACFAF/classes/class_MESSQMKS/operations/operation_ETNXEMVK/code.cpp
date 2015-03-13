//~~ void trace_initialize_end() [AQF_MessageReceiver] ~~
if (m_tracefile)
{
    *m_tracefile 
        << "<"
        << "["
        << QDateTime().currentMSecsSinceEpoch() 
        << "]{" 
        << QThread::currentThread() 
        << "}" 
        << std::endl;
}
