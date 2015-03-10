//~~ void CodeActions() [StateChartCoderQt] ~~

spec << "\t//************* actions **************************" << std::endl;

std::set<wxString> aSet = myAdeStatechart->GetActions();

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); ++iter)
	spec << "\tvirtual void "
		<< iter->utf8_str()
		<< "(const QString& port, const "
		<< myAdeStatechart->GetEventType().utf8_str()
		<< "& theEvent) = 0;"
		<< std::endl;
