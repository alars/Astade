//~~ void CodeEnterState(AdeState& theState) [StateChartCoderACFp] ~~
spec << "\t//! @brief This is the enter function for state "
	<< theState.GetName().c_str()
	<< "."
	<< std::endl;
spec << "\tvoid Enter_"
	<< theState.GetName().c_str()
	<< "("
	<< myAdeStatechart->GetEventType().c_str()
	<< "* theEvent);\n"
	<< std::endl;

impl << "void "
	<< myAdeStatechart->GetName().c_str()
	<< "::Enter_"
	<< theState.GetName().c_str()
	<< "("
	<< myAdeStatechart->GetEventType().c_str()
	<< "* theEvent)"
	<< std::endl;
impl << "{" << std::endl;

impl << "\t// Set the new state." << std::endl;
impl << "\ttheState = &"
	<< myAdeStatechart->GetName().c_str()
	<< "::"
	<< theState.GetName().c_str()
	<< ";"
	<< std::endl;

wxString EntryAction = theState.GetEntryAction();
if (!EntryAction.empty())
{
	impl << "\t// Call Entry Action." << std::endl;
	impl << "\t"
		<< EntryAction.c_str()
		<< "(theEvent);"
		<< std::endl;
}

impl << "\t// call the virtual notify function" << std::endl;
impl << "\tnotifyNewState(\"" << theState.GetName().c_str() << "\");\n" << std::endl;

impl << "\t// maybe trace the state entering" << std::endl;
impl << "\t#ifdef _TRACE_" << std::endl;
impl << "\tACF_Trace_notify_state(&MessageReceiver_base, 5, \""
	<< myAdeStatechart->GetName().c_str()
	<< "\", \""
	<< theState.GetName().c_str()
	<< "\");"
	<< std::endl;
impl << "\t#endif" << std::endl;

wxString aTimeout = theState.GetTimeout();
if (!aTimeout.empty())
{
	long value = 0;
	if (aTimeout.ToLong(&value) && value != 0)
	{
		impl << "\t// Start Timer." << std::endl;
		impl << "\tACF_scheduleTimeout(&MessageReceiver_base, "
			<< aTimeout.c_str()
			<< ");"
			<< std::endl;
	}
}

AdeElementIterator it;
for (it = theState.begin(); it != theState.end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = dynamic_cast<AdeTransition*>(anElement);
		if (!aTransition->GetGuard().empty())
			CodeEventlessTransition(theState, *aTransition);
	}
	delete anElement;
}

for (it = theState.begin(); it != theState.end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = dynamic_cast<AdeTransition*>(anElement);
		if (aTransition->GetGuard().empty())
			CodeEventlessTransition(theState, *aTransition);
	}
	delete anElement;
}

impl << "\tnextState = 0; // We stay in this state" << std::endl;
impl << "}\n" << std::endl;
