LOCK();
pthread_t thread = pthread_self();

object = NULL;
name = NULL;

for(unsigned int i=0; i<ms_threadCount; ++i)
{
  if (ms_runningThreads[i] == thread)
  {
    object = ms_runningObjects[i];
    if (ms_runningNames[i]!=NULL)
    {
      name = new char[strlen( ms_runningNames[i] )+1];
      strcpy( name, ms_runningNames[i] );
    }
    break;
  }
}
UNLOCK();
