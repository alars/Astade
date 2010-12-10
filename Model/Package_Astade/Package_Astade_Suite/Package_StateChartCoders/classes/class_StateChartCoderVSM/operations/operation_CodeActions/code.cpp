//~~ void CodeActions() [StateChartCoderVSM] ~~

spec << "\t//************* actions **************************"  << std::endl;

std::set<wxString> aSet = myAdeStatechart->GetActions();

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); ++iter)
	spec << "\tvirtual void "
		<< (*iter).c_str()
		<< "("
		<< myAdeStatechart->GetEventType().c_str()
		<< "& message) = 0;"
		<< std::endl;
