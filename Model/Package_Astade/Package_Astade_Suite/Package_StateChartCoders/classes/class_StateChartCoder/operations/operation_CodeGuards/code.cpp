spec << "\t//************* guards **************************" << std::endl;

std::set<wxString> aSet = myAdeStatechart->GetGuards();

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); ++iter)
	spec << "\tvirtual bool "
		<< (*iter).c_str()
		<< "("
		<< myAdeStatechart->GetEventType().c_str()
		<< "& theEvent) = 0;\n"
		<< std::endl;
