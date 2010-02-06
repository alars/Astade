if (m_level > tracelevel)
{
	const char* flag = NULL;
	switch (m_NotificationType)
	{
		case CALL_DESTRUCTOR:
			flag = " (X) ";
			break;

		case CALL_NOTIFICATION:
			flag = " <== ";
			break;
	}
	if (flag)
	{
		if (m_PreviousRunningObjectPointer)
			std::cerr << m_PreviousRunningObjectPointer << ":";
		std::cerr << m_PreviousRunningObject << flag;

		if (ms_RunningObjectPointer)
			std::cerr << ms_RunningObjectPointer << ":";
		std::cerr << ms_RunningObject;

		if (m_ReturnString)
			std::cerr << " " << m_ReturnString;

		std::cerr << std::endl;
	}
}

ms_RunningObject = m_PreviousRunningObject;
ms_RunningObjectPointer = m_PreviousRunningObjectPointer;
