//~~ void CodeActions() [StateChartCoderQt] ~~

spec << "\t//************* actions **************************" << std::endl;

std::set<wxString> aSet = myAdeStatechart->GetActions();

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); ++iter)
{
    spec << "\t/// @brief virtual action which has to be overload by the implementer of the state chart." << std::endl;
    spec << "\t/// @param port The machine which send this message." << std::endl;
    spec << "\t/// @param theEvent The event passed to the actions and guards." << std::endl;
	spec << "\tvirtual void "
		<< iter->utf8_str()
		<< "(const AQF_MessageReceiver* port, const "
		<< myAdeStatechart->GetEventType().utf8_str()
		<< "& theEvent) = 0;"
		<< std::endl;
}