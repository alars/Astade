if (!pause_output && ms_ofile.is_open())
	ms_ofile  << objectPointer << ":" << objectName << " >>> " << stateName << std::endl;