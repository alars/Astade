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
	case CALL_DESTRUCTOR:
		wxLogTrace( m_RunningObject, "%s (X) %s ", orig, dest);
	break;

	case CALL_NOTIFICATION:
		wxLogTrace( m_RunningObject, "%s <== %s", orig, dest);
	break;
}

m_RunningObject = m_PreviousRunningObject;
m_RunningObjectPointer = m_PreviousRunningObjectPointer;