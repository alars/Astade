if(m_level>ms_tracelevel)
{

  GetRunning(m_callerObject, m_callerName);
  SetRunning(objectPointer, objectName);

  pthread_t thread = pthread_self();
  
  switch(m_notificationType)
  {
    case notify_constructor:
      if (m_callerObject && m_callerName)
      {
        PRINT_LOG (" %s@%p (!) %s@%p\n", m_callerName, m_callerObject, objectName, objectPointer );
      }
      else
      {
        PRINT_LOG( " * (!) %s@%p\n", objectName, objectPointer );
      }
    break;

    case notify_destructor:
      PRINT_LOG( "; %s@%p is going to be destroyd\n", objectName, objectPointer );
    break;

    case notify_function_call:
      if (m_callerObject && m_callerName)
      {
        PRINT_LOG( " %s@%p ==> %s@%p %s()<%lu>\n", m_callerName, m_callerObject, objectName, objectPointer, functionName, (unsigned long int)thread );
      }
      else
      {
        PRINT_LOG( " * ==> %s@%p %s()<%lu>\n", objectName, objectPointer, functionName, (unsigned long int)thread );
      }
    break;

    default:
      PRINT_LOG( "# unknown notification type occured (%d)!\n", m_notificationType );
    break;
  }

}