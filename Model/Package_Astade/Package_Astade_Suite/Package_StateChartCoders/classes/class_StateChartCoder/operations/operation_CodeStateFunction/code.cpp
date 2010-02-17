wxString description(theState.GetDescription());
if (!description.empty())
{
	spec << "/** "
		<< description.c_str()
		<< std::endl;
	spec << "*/" << std::endl;
}
else
    spec << "\t//! @brief This is the state function for state "
		<< theState.GetName().c_str()
		<< std::endl;

spec << "\tbool "
	<< theState.GetName().c_str()
	<< "("
	<< myAdeStatechart->GetEventType().c_str()
	<< "& theEvent, eventIDs itsID);\n"
	<< std::endl;

impl << "bool "
	<< myAdeStatechart->GetName().c_str()
	<< "::"
	<< theState.GetName().c_str()
	<< "("
	<< myAdeStatechart->GetEventType().c_str()
	<< "& theEvent, eventIDs itsID)"
	<< std::endl;
impl << "{" << std::endl;

AdeElementIterator it;
for (it = theState.begin(); it != theState.end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = dynamic_cast<AdeTransition*>(anElement);
		if (!aTransition->GetGuard().empty())
			CodeTransition(theState, *aTransition);
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
			CodeTransition(theState, *aTransition);
	}
	delete anElement;
}

impl << "\t// not handled" << std::endl;
impl << "\treturn false;" << std::endl;
impl << "}\n" << std::endl;
