//~~ void trace_send(const AQF_Message& event, AQF_MessageReceiver*& destObject) [AQF_MessageReceiver] ~~
if (m_tracefile)
{
    int status;
    char *myname = abi::__cxa_demangle(typeid(*this).name(), 0, 0, &status);
    char *destname = abi::__cxa_demangle(typeid(*destObject).name(), 0, 0, &status);
    *m_tracefile << (void*)this << ":" << myname << " >-- " 
                 << (void*)destObject << ":" << destname << std::endl;
}