//~~ void Timestamp() [wxTrace2file] ~~

wxDateTime now(wxDateTime::UNow());

ms_ofile << "["
	<< now.FormatISOTime()
	<< "." << std::setw(3) << std::setfill('0')
	<< now.GetMillisecond()
	<< "] ";
