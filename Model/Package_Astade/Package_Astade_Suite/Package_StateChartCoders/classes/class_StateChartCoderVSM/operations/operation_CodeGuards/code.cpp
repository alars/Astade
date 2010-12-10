//~~ void CodeGuards() [StateChartCoderVSM] ~~

spec << "\t//************* guards **************************" << std::endl;

std::set<wxString> aSet = myAdeStatechart->GetGuards();

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); ++iter)
	spec << "\tvirtual bool "
		<< (*iter).c_str()
		<< "("
		<< myAdeStatechart->GetEventType().c_str()
		<< "& message) = 0;"
		<< std::endl;
