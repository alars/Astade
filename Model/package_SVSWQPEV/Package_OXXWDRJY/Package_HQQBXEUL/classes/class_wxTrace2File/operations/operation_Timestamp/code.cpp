wxDateTime now(wxDateTime::UNow());

ms_ofile << "["
	<< (const char*)now.FormatISOTime().c_str()
	<< "." << std::setw(3) << std::setfill('0')
	<< now.GetMillisecond()
	<< "] "
	<< std::endl;
