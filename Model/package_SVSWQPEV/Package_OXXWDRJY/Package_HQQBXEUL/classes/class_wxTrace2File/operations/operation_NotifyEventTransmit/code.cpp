if (ms_ofile.is_open())
{
	wxMutexLocker lock(myMutex);

	Timestamp();

	if (ms_RunningObjectPointer[wxThread::GetCurrentId()])
		ms_ofile << ms_RunningObjectPointer[wxThread::GetCurrentId()]
		         << ":";
	if (ms_RunningObject[wxThread::GetCurrentId()])
		ms_ofile << ms_RunningObject[wxThread::GetCurrentId()];
	else
		ms_ofile << "???";
	ms_ofile << " >-- "
	         << destinationObjectPointer
	         << ":"
	         << destinationObjectName
	         << " "
	         << eventName
	         << std::endl;
}
