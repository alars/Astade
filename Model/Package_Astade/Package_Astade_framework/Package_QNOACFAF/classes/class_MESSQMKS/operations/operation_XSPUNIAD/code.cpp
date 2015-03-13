//~~ void trace_state(const char* statename) [AQF_MessageReceiver] ~~
if (m_tracefile)
{
    int status;
    char *realname = abi::__cxa_demangle(typeid(*this).name(), 0, 0, &status);
    *m_tracefile << "[" << QDateTime().currentMSecsSinceEpoch() << "]{" << QThread::currentThread() << "}"
        << (void*)this << ":" << realname << " >>> " << statename << std::endl;
}
