//~~ void CodeGuards() [StateChartCoderQt] ~~

spec << "\t//************* guards **************************" << std::endl;

std::set<wxString> aSet = myAdeStatechart->GetGuards();

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); ++iter)
	spec << "\tvirtual bool "
		<< iter->utf8_str()
		<< "(const QString& port, const "
		<< myAdeStatechart->GetEventType().utf8_str()
		<< "& theEvent) = 0;"
		<< std::endl;
