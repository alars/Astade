//~~ void notify_message_sent(const void* sourcePointer, const char* sourceName, const void* destinationPointer, const char* destinationName, const char* eventName) [Trace2UML] ~~

if ((sourcePointer == 0) || (sourceName == 0) || (destinationPointer == 0) || (destinationName == 0) || (eventName == 0))
    return;

while (sem_wait(&msSemaphore))
    ;

traceTimestamp();
    
ms_ofile << sourcePointer << ":" << sourceName << " >-- " << destinationPointer << ":" << destinationName << " " << eventName << std::endl;    

ms_ofile.flush();
sem_post(&msSemaphore);