//~~ void CodeEnterState(AdeState& theState, AdeStatechart& theStatechart) [StateChartCoderQt] ~~

spec << "\t//! @brief This is the enter function for state "
	<< theState.GetName().utf8_str()
	<< "."
	<< std::endl;
spec << "\tbool Enter_"
	<< theState.GetName().utf8_str()
	<< "(const AQF_MessageReceiver* port, const "
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "& theEvent);\n"
	<< std::endl;

impl << "bool "
	<< myAdeStatechart->GetName().utf8_str()
	<< "::Enter_"
	<< theState.GetName().utf8_str()
	<< "(const AQF_MessageReceiver* port, const "
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "& theEvent)"
	<< std::endl;
impl << "{" << std::endl;
impl << "\tQ_UNUSED(port)" << std::endl;
impl << "\tQ_UNUSED(theEvent)" << std::endl;

impl << "\t// Set the new state." << std::endl;
impl << "\ttheState = &"
	<< myAdeStatechart->GetName().utf8_str()
	<< "::"
	<< theState.GetName().utf8_str()
	<< ";"
	<< std::endl;

wxString EntryAction = theState.GetEntryAction();
if (!EntryAction.empty())
{
	impl << "\t// Call Entry Action." << std::endl;
	impl << "\t"
		<< EntryAction.utf8_str()
		<< "(port, theEvent);"
		<< std::endl;
}

impl << "\t// call the virtual notify function" << std::endl;
impl << "\tnotifyNewState(\"" << theState.GetName().utf8_str() << "\");\n" << std::endl;

impl << "\t// maybe trace the state entering" << std::endl;
impl << "\ttrace_state(\"" << theState.GetName().utf8_str() << "\");" << std::endl;

wxString aTimeout = theState.GetTimeout().Trim(true).Trim(false);

if (!aTimeout.empty())
{
    impl << "\t// Start Timer." << std::endl;
    impl << "\tscheduleTimeout(" << aTimeout.utf8_str() << ");" << std::endl;
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

//**************

for (it = theStatechart.begin(); it != theStatechart.end(); ++it)
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

for (it = theStatechart.begin(); it != theStatechart.end(); ++it)
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
impl << "\treturn true; // Continue handling this state chart" << std::endl;
impl << "}\n" << std::endl;
