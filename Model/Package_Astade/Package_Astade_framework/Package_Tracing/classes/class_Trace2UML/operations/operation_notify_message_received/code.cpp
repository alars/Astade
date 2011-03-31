//~~ void notify_message_received(const void* sourcePointer, const char* sourceName, const void* destinationPointer, const char* destinationName, const char* eventName) [Trace2UML] ~~

if ((destinationPointer == 0) || (destinationName == 0) || (eventName == 0))
    return;

while (sem_wait(&msSemaphore))
    ;

traceTimestamp();
    
if ((sourcePointer == 0) || sourceName == 0)
{
    ms_ofile << "~ --> " << destinationPointer << ":" << destinationName << " " << eventName << std::endl;
}
else
{
    ms_ofile << sourcePointer << ":" << sourceName << " --> " << destinationPointer << ":" << destinationName << " " << eventName << std::endl;
}    
    
ms_ofile.flush();
sem_post(&msSemaphore);