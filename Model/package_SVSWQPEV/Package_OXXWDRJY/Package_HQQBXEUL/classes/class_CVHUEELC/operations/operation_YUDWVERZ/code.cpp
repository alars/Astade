m_PreviousRunningObject = ms_RunningObject;
ms_RunningObject = objectName;

m_PreviousRunningObjectPointer = ms_RunningObjectPointer;
ms_RunningObjectPointer = objectPointer;

if (!pause_output)
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
			std::cerr << m_PreviousRunningObjectPointer << ":";
		std::cerr << m_PreviousRunningObject << flag;

		if (ms_RunningObjectPointer)
			std::cerr << ms_RunningObjectPointer << ":";
		std::cerr << ms_RunningObject << " ";

		if (functionName)
			std::cerr << functionName << "(";
		if (parameterList)
			std::cerr << parameterList;
		if (functionName)
			std::cerr << ")";

		std::cerr << std::endl;
	}
}
