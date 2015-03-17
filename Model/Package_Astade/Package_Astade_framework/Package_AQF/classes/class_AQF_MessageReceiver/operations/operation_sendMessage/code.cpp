//~~ void sendMessage(AQF_MessageReceiver* port, const AQF_Message& event) [AQF_MessageReceiver] ~~
if (m_tracefile)
{
    if (_semaphore)
        while (sem_wait(_semaphore));
    *m_tracefile << (void*)this << ":" << getName(this) << " >-- "
                 << (void*)port << ":" << getName(port) << " "
                 << event.getID() << std::endl;
    if (_semaphore)
        sem_post(_semaphore);
}
QMetaObject::invokeMethod(port, "TakeEventSlot", Qt::QueuedConnection,
                           Q_ARG(void*, this),
                           Q_ARG(AQF_Message, event));
