//~~ Trace2wxTrace(int notificationType, int level, const void* objectPointer, const char* objectName, const char* parameterList = 0, const char* functionName = 0) [Trace2wxTrace] ~~

m_PreviousRunningObject = ms_RunningObject;
ms_RunningObject = objectName;

m_PreviousRunningObjectPointer = ms_RunningObjectPointer;
ms_RunningObjectPointer = objectPointer;

if (m_level > tracelevel)
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
		case CALL_CONSTRUCTOR:
			wxLogTrace(ms_RunningObject, wxS("%s (!) %s "), orig, dest);
			break;

		case CALL_NOTIFICATION:
			wxLogTrace(ms_RunningObject, wxS("%s ==> %s %s()"), orig, dest, functionName);
			break;

		case CALL_EVENTRECEIVE:
			wxLogTrace(ms_RunningObject, wxS("%s --> %s %s"), orig, dest, parameterList);
			break;
	}
}
