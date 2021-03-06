//~~ void staticSendMessage(AQF_MessageReceiver* port, const AQF_Message& event) [AQF_MessageReceiver] ~~
if (port->m_tracefile)
{
    if (port->_semaphore)
        while (sem_wait(port->_semaphore));
    *port->m_tracefile << "~ >-- "
                 << (void*)port << ":" << getName(port) << " "
                 << event.getID() << std::endl;
    if (port->_semaphore)
        sem_post(port->_semaphore);
}
QMetaObject::invokeMethod(port, "TakeEventSlot", Qt::QueuedConnection,
                           Q_ARG(void*, 0),
                           Q_ARG(AQF_Message, event));
