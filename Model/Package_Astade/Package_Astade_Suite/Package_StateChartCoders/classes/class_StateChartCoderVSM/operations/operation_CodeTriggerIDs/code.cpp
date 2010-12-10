//~~ void CodeTriggerIDs() [StateChartCoderVSM] ~~

spec << "\t// The following event IDs are used:" << std::endl;

std::set<wxString> aSet = myAdeStatechart->GetTrigger();

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); ++iter)
	spec << "\t// "
		<< (*iter).c_str()
		<< "\n"
		<< std::endl;

spec << std::endl;
