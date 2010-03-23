spec << "\t//! @brief This is the enter function for state "
	<< theState.GetName().c_str()
	<< "."
	<< std::endl;
spec << "\tvoid Enter_"
	<< theState.GetName().c_str()
	<< "("
	<< myAdeStatechart->GetEventType().c_str()
	<< "& theEvent);\n"
	<< std::endl;

impl << "void "
	<< myAdeStatechart->GetName().c_str()
	<< "::Enter_"
	<< theState.GetName().c_str()
	<< "("
	<< myAdeStatechart->GetEventType().c_str()
	<< "& theEvent)"
	<< std::endl;
impl << "{" << std::endl;

wxString EntryAction = theState.GetEntryAction();
if (!EntryAction.empty())
{
	impl << "\t// Call Entry Action." << std::endl;
	impl << "\t"
		<< EntryAction.c_str()
		<< "(theEvent);"
		<< std::endl;
}

impl << "\tNOTIFY_STATE_CHANGE(\""
	<< myAdeStatechart->GetName().c_str()
	<< "\",\""
	<< theState.GetName().c_str()
	<< "\")"
	<< std::endl;

wxString aTimeout = theState.GetTimeout();
if (!aTimeout.empty())
{
	long value = 0;
	if (!aTimeout.ToLong(&value))
	{
		impl << "\t// Start Timer." << std::endl;
		impl << "\tif ("
			<< aTimeout.c_str()
			<< " != 0)"
			<< std::endl;
		impl << "\t\tStart("
			<< aTimeout.c_str()
			<< ", true);"
			<< std::endl;
	}
	else if (value != 0)
		impl << "\tStart("
			<< aTimeout.c_str()
			<< ", true);"
			<< std::endl;
}

impl << "\t// Set the new state." << std::endl;
impl << "\ttheState = &"
	<< myAdeStatechart->GetName().c_str()
	<< "::"
	<< theState.GetName().c_str()
	<< ";"
	<< std::endl;

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
