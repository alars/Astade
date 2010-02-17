spec << "\tenum eventIDs" << std::endl;
spec << "\t{" << std::endl;

std::set<wxString> aSet = myAdeStatechart->GetTrigger();

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); ++iter)
	spec << "\t\tID_"
		<< (*iter).c_str()
		<< ","
		<< std::endl;

spec << "\t};\n" << std::endl;
