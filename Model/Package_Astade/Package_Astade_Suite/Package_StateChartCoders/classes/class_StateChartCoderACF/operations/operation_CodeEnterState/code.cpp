//~~ void CodeEnterState(AdeState& theState) [StateChartCoderACF] ~~
spec << "//! @brief This is the enter function for state "
	<< theState.GetName().c_str()
	<< "."
	<< std::endl;
spec << "void "
	<< myAdeStatechart->GetName().c_str()
	<< "_Enter_"
	<< theState.GetName().c_str()
	<< "("
	<< myAdeStatechart->GetName().c_str()
	<< "* me, "
	<< myAdeStatechart->GetEventType().c_str()
	<< "* theEvent);\n"
	<< std::endl;

impl << "void "
	<< myAdeStatechart->GetName().c_str()
	<< "_Enter_"
	<< theState.GetName().c_str()
	<< "("
	<< myAdeStatechart->GetName().c_str()
	<< "* me, "
	<< myAdeStatechart->GetEventType().c_str()
	<< "* theEvent)"
	<< std::endl;
impl << "{" << std::endl;

impl << "\t// Set the new state." << std::endl;
impl << "\tme->theState = &"
	<< myAdeStatechart->GetName().c_str()
	<< "_"
	<< theState.GetName().c_str()
	<< ";"
	<< std::endl;

wxString EntryAction = theState.GetEntryAction();
if (!EntryAction.empty())
{
	impl << "\t// Call Entry Action." << std::endl;
	impl << "\t"
		<< myAdeStatechart->GetName().c_str()
		<< "_impl_"
		<< EntryAction.c_str()
		<< "(("
		<< myAdeStatechart->GetName().c_str()
		<< "_impl*)me, theEvent);"
		<< std::endl;
}

impl << "\t// maybe trace the state entering" << std::endl;
impl << "\t#ifdef _TRACE_" << std::endl;
impl << "\tACF_Trace_notify_state(&me->MessageReceiver_base, 5, \""
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
		impl << "\tACF_scheduleTimeout(&me->MessageReceiver_base, "
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

impl << "\tme->nextState = 0; // We stay in this state" << std::endl;
impl << "}\n" << std::endl;
