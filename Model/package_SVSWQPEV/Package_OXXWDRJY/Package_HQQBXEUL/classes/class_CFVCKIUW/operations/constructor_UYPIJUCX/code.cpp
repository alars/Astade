m_PreviousRunningObject = m_RunningObject;
m_RunningObject = objectName;

m_PreviousRunningObjectPointer = m_RunningObjectPointer;
m_RunningObjectPointer = objectPointer;

char orig[100];
char dest[100];

if (m_PreviousRunningObjectPointer)
	sprintf(orig,"%p:%s",m_PreviousRunningObjectPointer,m_PreviousRunningObject);
else
	strcpy(orig,m_PreviousRunningObject);

if (m_RunningObjectPointer)
	sprintf(dest,"%p:%s",m_RunningObjectPointer,m_RunningObject);
else
	strcpy(dest,m_RunningObject);

switch (m_NotificationType)
{
	case CALL_CONSTRUCTOR:
		wxLogMessage( "%s (!) %s ", orig, dest);
		//wxLogTrace( m_RunningObject, "%s (!) %s ", orig, dest);
	break;

	case CALL_NOTIFICATION:
		wxLogTrace( m_RunningObject, "%s ==> %s %s()", orig, dest, functionName);
	break;

	case CALL_EVENTRECEIVE:
		wxLogTrace( m_RunningObject, "%s --> %s %s", orig, dest, parameterList);
	break;
}