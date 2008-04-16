m_PreviousRunningObject = ms_RunningObject[wxThread::GetCurrentId()];
ms_RunningObject[wxThread::GetCurrentId()] = objectName;

m_PreviousRunningObjectPointer = ms_RunningObjectPointer[wxThread::GetCurrentId()];
ms_RunningObjectPointer[wxThread::GetCurrentId()] = objectPointer;

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
		mySemaphore->Wait();

		if (m_PreviousRunningObjectPointer && (m_NotificationType != CALL_EVENTRECEIVE))
		{
			ms_ofile << m_PreviousRunningObjectPointer << ":";
			ms_ofile << m_PreviousRunningObject << flag;
		}
		else
		if (m_NotificationType == CALL_EVENTRECEIVE)
			ms_ofile << "???" << flag;
		else
			ms_ofile << "*" << flag;


		if (ms_RunningObjectPointer[wxThread::GetCurrentId()])
			ms_ofile << ms_RunningObjectPointer[wxThread::GetCurrentId()] << ":";
		ms_ofile << ms_RunningObject[wxThread::GetCurrentId()] << " ";

		if (functionName)
			ms_ofile << functionName << "(";
		if (parameterList)
			ms_ofile << parameterList;
		if (functionName)
			ms_ofile << ")";

		ms_ofile << std::endl;

		mySemaphore->Post();
	}
}
