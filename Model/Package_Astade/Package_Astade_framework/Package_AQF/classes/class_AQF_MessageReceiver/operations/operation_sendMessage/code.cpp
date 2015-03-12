//~~ void sendMessage(AQF_MessageReceiver* port, const AQF_Message& event) [AQF_MessageReceiver] ~~
if (m_tracefile)
{
    int status1;
    char *myname = abi::__cxa_demangle(typeid(*this).name(), 0, 0, &status1);
    int status2;
    char *destname = abi::__cxa_demangle(typeid(*port).name(), 0, 0, &status2);
    *m_tracefile << (void*)this << ":" << myname << " >-- "
                 << (void*)port << ":" << destname << " "
                 << event.getID() << std::endl;
}
QMetaObject::invokeMethod(port, "TakeEventSlot", Qt::QueuedConnection,
                           Q_ARG(void*, this),
                           Q_ARG(AQF_Message, event));
