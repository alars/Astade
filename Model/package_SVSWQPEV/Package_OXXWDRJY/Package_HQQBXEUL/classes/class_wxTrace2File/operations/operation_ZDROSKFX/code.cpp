if (ms_ofile.is_open())
{
	if (ms_RunningObjectPointer[wxThread::GetCurrentId()])
		ms_ofile << ms_RunningObjectPointer[wxThread::GetCurrentId()]
		         << ":";
	ms_ofile << ms_RunningObject[wxThread::GetCurrentId()]
	         << " >-- "
	         << destinationObjectPointer
	         << ":"
	         << destinationObjectName
	         << " "
	         << eventName
	         << std::endl;
}
