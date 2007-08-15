if (!pause_output && ms_ofile.is_open())
{
	if (ms_RunningObjectPointer[wxThread::GetCurrentId()])
		ms_ofile << ms_RunningObjectPointer[wxThread::GetCurrentId()] << ":";
	ms_ofile << ms_RunningObject[wxThread::GetCurrentId()] << " ";
	ms_ofile  << ">-- " << destinationObjectPointer << ":" << destinationObjectName << " " << eventName << std::endl;
}