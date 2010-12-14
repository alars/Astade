//~~ void CodeEnterState(AdeState& theState) [StateChartCoderVSM] ~~

spec << "\t//! @brief This is the enter function for state "
	<< theState.GetName().c_str()
	<< "."
	<< std::endl;
spec << "\tvoid Enter_"
	<< theState.GetName().c_str()
	<< "("
	<< myAdeStatechart->GetEventType().c_str()
	<< "& message);\n"
	<< std::endl;

impl << "void "
	<< myAdeStatechart->GetName().c_str()
	<< "::Enter_"
	<< theState.GetName().c_str()
	<< "("
	<< myAdeStatechart->GetEventType().c_str()
	<< "& message)"
	<< std::endl;
impl << "{" << std::endl;
impl << "\tNOTIFY_STATE_CHANGE(\""
	<< myAdeStatechart->GetName().c_str()
	<< "\",\""
	<< theState.GetName().c_str()
	<< "\")"
	<< std::endl;

wxString aTimeout = theState.GetTimeout();
if (!aTimeout.empty())
{
	impl << "\t//Start Timer." << std::endl;
	impl << "\tif (m_RunningTimer)" << std::endl;
	impl << "\t\t"
		<< myAdeStatechart->GetEventType().c_str()
		<< "::Delete(m_RunningTimer);"
		<< std::endl;
	impl << "\tm_RunningTimer = NEWMESSAGE(dIID_VFSM_MSG_AbbruchTimer)->Send(0,"
		<< aTimeout.c_str()
		<< ");\n"
		<< std::endl;
}

wxString EntryAction = theState.GetEntryAction();
if (!EntryAction.empty())
{
	impl << "\t// Call Entry Action." << std::endl;
	impl << "\t"
		<< EntryAction.c_str()
		<< "(message);"
		<< std::endl;
}

impl << "\t// Set the new state." << std::endl;
impl << "\tSETSTATE("
	<< theState.GetName().c_str()
	<< ");"
	<< std::endl;

AdeElementIterator it;
for (it = theState.begin(); it != theState.end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = static_cast<AdeTransition*>(anElement);
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
		AdeTransition* aTransition = static_cast<AdeTransition*>(anElement);
		if (aTransition->GetGuard().empty())
			CodeEventlessTransition(theState, *aTransition);
	}
	delete anElement;
}

impl << "\tnextState = 0; // We stay in this state" << std::endl;

impl << "}\n" << std::endl;
