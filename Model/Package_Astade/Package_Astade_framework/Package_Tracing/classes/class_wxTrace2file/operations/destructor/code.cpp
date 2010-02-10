wxMutexLocker lock(myMutex);

if (m_level > tracelevel && ms_ofile.is_open())
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
		Timestamp();

		if (m_PreviousRunningObjectPointer)
		{
			ms_ofile << m_PreviousRunningObjectPointer << ":";
			ms_ofile << m_PreviousRunningObject << flag;
		}
		else
			ms_ofile << "*" << flag;

		if (ms_RunningObjectPointer[wxThread::GetCurrentId()])
			ms_ofile << ms_RunningObjectPointer[wxThread::GetCurrentId()] << ":";
		ms_ofile << ms_RunningObject[wxThread::GetCurrentId()];

		if (m_ReturnString)
			ms_ofile << " " << m_ReturnString;

		ms_ofile << std::endl;
	}
}

ms_RunningObject[wxThread::GetCurrentId()] = m_PreviousRunningObject;
ms_RunningObjectPointer[wxThread::GetCurrentId()] = m_PreviousRunningObjectPointer;
