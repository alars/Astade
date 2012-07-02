//~~ void CodeEventlessTransition(AdeState& theState, AdeTransition& theTransition) [StateChartCoderC] ~~

wxString event = theTransition.GetTrigger();
if (!event.empty() || theTransition.IsInternalTransition())
	return;

wxString guard = theTransition.GetGuard();

impl << "\t// "
	<< theTransition.GetLabel().utf8_str()
	<< std::endl;

if (guard.empty())
	impl << "\tif (true)" << std::endl;
else
	impl << "\tif ("
		<< myAdeStatechart->GetName().utf8_str()
		<< "_impl_"
		<< theTransition.GetGuard().utf8_str()
		<< "(me->myHandler, theEvent))"
		<< std::endl;
impl << "\t{" << std::endl;

std::list<wxString> aList = theTransition.GetActions();

if (!aList.empty())
	impl << "\t\t// Actions" << std::endl;

for (std::list<wxString>::iterator iter = aList.begin(); iter != aList.end();  iter++)
	impl << "\t\t"
		<< myAdeStatechart->GetName().utf8_str()
		<< "_impl_"
		<< iter->utf8_str()
		<< "(me->myHandler, theEvent);"
		<< std::endl;

wxString ExitAction = theState.GetExitAction();
if (!ExitAction.empty())
{
	impl << "\t\t// exit action" << std::endl;
	impl << "\t\t"
		<< myAdeStatechart->GetName().utf8_str()
		<< "_impl_"
		<< ExitAction.utf8_str()
		<< "(theEvent);"
		<< std::endl;
}
if (!theState.GetTimeout().empty())
{
	impl << "\t\t// Stop Timer" << std::endl;
	impl << "\t\t"
		<< myAdeStatechart->GetName().utf8_str()
		<< "_impl_StopTimer(me->myHandler);"
		<< std::endl;
}

impl << "\t\t// next state" << std::endl;
impl << "\t\tme->nextState = &"
		<< myAdeStatechart->GetName().utf8_str()
		<< "_Enter_"
		<< theTransition.GetDestination().utf8_str()
		<< ";"
		<< std::endl;

impl << "\t}" << std::endl;
impl << "\telse" << std::endl;
