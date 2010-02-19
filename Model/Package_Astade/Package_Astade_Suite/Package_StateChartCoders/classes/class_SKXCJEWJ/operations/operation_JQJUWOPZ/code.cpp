wxString event = theTransition.GetTrigger();
if (!event.empty() || theTransition.IsInternalTransition())
	return;

wxString guard = theTransition.GetGuard();

impl << "\t// "
	<< theTransition.GetLabel().c_str()
	<< std::endl;

if (guard.empty())
	impl << "\tif (1)" << std::endl;
else
	impl << "\tif ("
		<< theTransition.GetGuard().c_str()
		<< "(theEvent))"
		<< std::endl;
impl << "\t{" << std::endl;

std::list<wxString> aList = theTransition.GetActions();

if (!aList.empty())
	impl << "\t\t// Actions" << std::endl;

for (std::list<wxString>::iterator iter = aList.begin(); iter != aList.end(); ++iter)
	impl << "\t\t"
		<< (*iter).c_str()
		<< "(theEvent);"
		<< std::endl;

wxString nextState = theTransition.GetDestination();

if (!theState.GetExitAction().empty())
{
	impl << "\t\t// exit action" << std::endl;
	impl << "\t\t"
		<< theState.GetExitAction().c_str()
		<< "(theEvent);"
		<< std::endl;
}
if (!theState.GetTimeout().empty())
{
	impl << "\t\t// Stop Timer" << std::endl;
	impl << "\t\tACF_cancelTimeout(&me->MessageReceiver_base);" << std::endl;
}
impl << "\t\t// next state" << std::endl;
impl << "\t\tnextState = &"
	<< myAdeStatechart->GetName().c_str()
	<< "::Enter_"
	<< nextState.c_str()
	<< ";"
	<< std::endl;

impl << "\t}" << std::endl;
impl << "\telse" << std::endl;    
