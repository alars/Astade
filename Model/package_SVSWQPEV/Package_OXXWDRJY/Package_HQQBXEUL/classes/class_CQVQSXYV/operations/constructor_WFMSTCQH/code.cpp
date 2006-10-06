m_PreviousRunningObject = ms_RunningObject;
ms_RunningObject = objectName;

m_PreviousRunningObjectPointer = ms_RunningObjectPointer;
ms_RunningObjectPointer = objectPointer;

if (!pause_output && ms_ofile.is_open())
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
