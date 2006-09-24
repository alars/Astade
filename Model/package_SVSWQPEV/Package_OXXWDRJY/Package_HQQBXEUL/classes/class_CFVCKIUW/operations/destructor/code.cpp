if (!pause_output)
{
	char orig[100];
	char dest[100];

	if (m_PreviousRunningObjectPointer)
		sprintf(orig, "%p:%s", m_PreviousRunningObjectPointer, m_PreviousRunningObject);
	else
		strcpy(orig, m_PreviousRunningObject);

	if (ms_RunningObjectPointer)
		sprintf(dest, "%p:%s", ms_RunningObjectPointer, ms_RunningObject);
	else
		strcpy(dest, ms_RunningObject);

	switch (m_NotificationType)
	{
		case CALL_DESTRUCTOR:
			wxLogTrace(ms_RunningObject, "%s (X) %s ", orig, dest);
			break;

		case CALL_NOTIFICATION:
			wxLogTrace(ms_RunningObject, "%s <== %s", orig, dest);
			break;
	}
}

ms_RunningObject = m_PreviousRunningObject;
ms_RunningObjectPointer = m_PreviousRunningObjectPointer;
