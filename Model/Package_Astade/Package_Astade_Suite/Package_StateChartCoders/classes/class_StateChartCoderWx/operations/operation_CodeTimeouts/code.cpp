spec << "\t//************* timeouts **************************" << std::endl;

std::set<wxString> aSet = myAdeStatechart->GetTimeouts();

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); ++iter)
	spec << "\tunsigned int "
		<< (*iter).c_str()
		<< ";"
		<< std::endl;
