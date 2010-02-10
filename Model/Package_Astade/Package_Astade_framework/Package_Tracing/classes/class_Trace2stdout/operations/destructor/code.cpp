const void* objectPointer = NULL;
char* objectName = NULL;

if(m_level>ms_tracelevel)
{
  GetRunning(objectPointer, objectName);
  SetRunning(m_callerObject, m_callerName);  

  switch(m_notificationType)
  {
    case notify_constructor:
      PRINT_LOG( "; %s@%p is created successfully\n", objectName, objectPointer );
    break;

    case notify_destructor:      
      if (m_callerObject && m_callerName)
      {
        PRINT_LOG(" %s@%p (X) %s@%p\n", m_callerName, m_callerObject, objectName, objectPointer );
      }
      else
      {
        PRINT_LOG(" * (X) %s@%p\n", objectName, objectPointer );
      }
      break;

    case notify_function_call:
      if (m_callerObject && m_callerName)
      {
        PRINT_LOG( " %s@%p <== %s@%p %s\n", m_callerName, m_callerObject, objectName, objectPointer, m_returnString );
      }
      else
      {
        PRINT_LOG( " * <== %s@%p %s\n", objectName, objectPointer, m_returnString );
      }
    break;

    default:
      PRINT_LOG( "# unknown notification type occured (%d)!\n", m_notificationType );
    break;
  }
}

delete [] m_returnString;
delete [] objectName;
delete [] m_callerName;
objectPointer = NULL;
m_callerObject = NULL;
