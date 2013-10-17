//~~ void CodeTransition(AdeState& theState, AdeTransition& theTransition) [StateChartCoderACFp] ~~

wxString event = theTransition.GetTrigger();
if (event.empty())
	return;

impl << "\t// "
	<< theTransition.GetLabel().utf8_str()
	<< std::endl;

wxString guard = theTransition.GetGuard();
if (guard.empty())
	impl << "\tif (theEvent->ID == "
		<< event.utf8_str()
		<< ")"
		<< std::endl;
else
	impl << "\tif (theEvent->ID == "
		<< event.utf8_str()
		<< " && "
		<< theTransition.GetGuard().utf8_str()
		<< "(theEvent))"
		<< std::endl;
impl << "\t{" << std::endl;

std::list<wxString> aList = theTransition.GetActions();

wxString nextState = theTransition.GetDestination();

if (!theTransition.IsInternalTransition())
{
	if (!theState.GetExitAction().empty())
	{
		impl << "\t\t// exit action" << std::endl;
		impl << "\t\t"
			<< theState.GetExitAction().utf8_str()
			<< "(theEvent);"
			<< std::endl;
	}
	if ((!theState.GetTimeout().empty()) && (event != wxS("ACF_timeout")))
	{
		impl << "\t\t// Stop Timer" << std::endl;
		impl << "\t\tACF_cancelTimeout(&MessageReceiver_base);" << std::endl;
	}
	impl << "\t\t// next state" << std::endl;

	if (theTransition.IsSelfTransition())
		impl << "\t\tnextState = &"
			<< myAdeStatechart->GetName().utf8_str()
			<< "::Enter_"
			<< theState.GetName().utf8_str()
			<< ";"
			<< std::endl;
	else if (theTransition.IsTerminateTransition())
		impl << "\t\tnextState = &"
			<< myAdeStatechart->GetName().utf8_str()
			<< "::Enter_NoState;"
			<< std::endl;
	else
		impl << "\t\tnextState = &"
			<< myAdeStatechart->GetName().utf8_str()
			<< "::Enter_"
			<< nextState.utf8_str()
			<< ";"
			<< std::endl;
}
else
	impl << "\t\t// internal Transition" << std::endl;

if (!aList.empty())
	impl << "\t\t// Actions" << std::endl;

for (std::list<wxString>::iterator iter = aList.begin(); iter != aList.end(); ++iter)
	impl << "\t\t"
		<< iter->utf8_str()
		<< "(theEvent);"
		<< std::endl;

impl << "\t\treturn;" << std::endl;
impl << "\t}" << std::endl;
impl << "\telse" << std::endl;
