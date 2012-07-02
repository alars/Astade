//~~ void CodeEventlessTransition(AdeState& theState, AdeTransition& theTransition) [StateChartCoderACFp] ~~

wxString event = theTransition.GetTrigger();
if (!event.empty() || theTransition.IsInternalTransition())
	return;

wxString guard = theTransition.GetGuard();

impl << "\t// "
	<< theTransition.GetLabel().utf8_str()
	<< std::endl;

if (guard.empty())
	impl << "\tif (1)" << std::endl;
else
	impl << "\tif ("
		<< theTransition.GetGuard().utf8_str()
		<< "(theEvent))"
		<< std::endl;
impl << "\t{" << std::endl;

if (!theState.GetExitAction().empty())
{
	impl << "\t\t// exit action" << std::endl;
	impl << "\t\t"
		<< theState.GetExitAction().utf8_str()
		<< "(theEvent);"
		<< std::endl;
}
if (!theState.GetTimeout().empty())
{
	impl << "\t\t// Stop Timer" << std::endl;
	impl << "\t\tACF_cancelTimeout(&MessageReceiver_base);" << std::endl;
}

std::list<wxString> aList = theTransition.GetActions();

if (!aList.empty())
	impl << "\t\t// Actions" << std::endl;

for (std::list<wxString>::iterator iter = aList.begin(); iter != aList.end(); ++iter)
	impl << "\t\t"
		<< iter->utf8_str()
		<< "(theEvent);"
		<< std::endl;

wxString nextState = theTransition.GetDestination();

impl << "\t\t// next state" << std::endl;
impl << "\t\tnextState = &"
	<< myAdeStatechart->GetName().utf8_str()
	<< "::Enter_"
	<< nextState.utf8_str()
	<< ";"
	<< std::endl;

impl << "\t}" << std::endl;
impl << "\telse" << std::endl;
