//~~ void CodeGuards() [StateChartCoderQt] ~~

spec << "\t//************* guards **************************" << std::endl;

std::set<wxString> aSet = myAdeStatechart->GetGuards();

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); ++iter)
{
    spec << "\t/// @brief virtual guard which has to be overload by the implementer of the state chart." << std::endl;
    spec << "\t/// @param port The machine which send this message." << std::endl;
    spec << "\t/// @param theEvent The event passed to the actions and guards." << std::endl;
    spec << "\t/// @return true, if the guard is true." << std::endl;
	spec << "\tvirtual bool "
		<< iter->utf8_str()
		<< "(const AQF_MessageReceiver* port, const "
		<< myAdeStatechart->GetEventType().utf8_str()
		<< "& theEvent) = 0;"
		<< std::endl;
}