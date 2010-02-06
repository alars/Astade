if (ms_ofile.is_open())
{
	wxMutexLocker lock(myMutex);

	Timestamp();
	ms_ofile  << objectPointer << ":" << objectName << " >>> " << stateName << std::endl;
}
