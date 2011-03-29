//~~ Trace2file(int notificationType, int level, const void* objectPointer, const char* objectName, const char* parameterList = 0, const char* functionName = 0) [Trace2file] ~~
m_PreviousRunningObject = ms_RunningObject;
ms_RunningObject = objectName;

m_PreviousRunningObjectPointer = ms_RunningObjectPointer;
ms_RunningObjectPointer = objectPointer;

if (m_level > tracelevel && ms_ofile.is_open())
{
	const char* flag = NULL;
	switch (m_NotificationType)
	{
		case CALL_CONSTRUCTOR:
			flag = " (!) ";
			break;

		case CALL_NOTIFICATION:
			flag = " ==> ";
			break;

		case CALL_EVENTRECEIVE:
			flag = " --> ";
			break;
	}
	if (flag)
	{
		if (m_PreviousRunningObjectPointer)
			ms_ofile << m_PreviousRunningObjectPointer << ":";
		ms_ofile << m_PreviousRunningObject << flag;

		if (ms_RunningObjectPointer)
			ms_ofile << ms_RunningObjectPointer << ":";
		ms_ofile << ms_RunningObject << " ";

		if (functionName)
			ms_ofile << functionName << "(";
		if (parameterList)
			ms_ofile << parameterList;
		if (functionName)
			ms_ofile << ")";

		ms_ofile << std::endl;
	}
}
