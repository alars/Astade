LOCK();
pthread_t thread = pthread_self();
bool found = false;

for(unsigned int i=0; i<ms_threadCount; ++i)
{
  if (ms_runningThreads[i] == thread)
  {  
    found = true;
    ms_runningObjects[i] = object;
    delete [] ms_runningNames[i];
    ms_runningNames[i] = NULL;
    if (name!=NULL)
    {
      ms_runningNames[i] = new char[strlen( name )+1];
      strcpy( ms_runningNames[i], name );
    }
    break;
  }
}

if ((!found) && (ms_threadCount<MAX_THREADS))
{
  PRINT_LOG("# new Thread (%lu) recognized\n", (unsigned long int)thread);
  ms_runningThreads[ms_threadCount] = thread;
  ms_runningObjects[ms_threadCount] = object;
  ms_runningNames[ms_threadCount] = NULL;
  if (name!=NULL)
  {
    ms_runningNames[ms_threadCount] = new char[strlen( name )+1];
    strcpy( ms_runningNames[ms_threadCount], name );
  }
  ++ms_threadCount;
}
UNLOCK();