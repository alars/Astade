if (!pause_output && ms_ofile.is_open())
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
			ms_ofile << m_PreviousRunningObjectPointer << ":";
		ms_ofile << m_PreviousRunningObject << flag;

		if (ms_RunningObjectPointer)
			ms_ofile << ms_RunningObjectPointer << ":";
		ms_ofile << ms_RunningObject;

		if (m_ReturnString)
			ms_ofile << " " << m_ReturnString;

		ms_ofile << std::endl;
	}
}

ms_RunningObject = m_PreviousRunningObject;
ms_RunningObjectPointer = m_PreviousRunningObjectPointer;
