wxString description(theState.GetDescription());
if (!description.empty())
{
	spec << "/** "
		<< description.c_str()
		<< std::endl;
	spec << "*/" << std::endl;
}
else
    spec << "//! @brief This is the state function for state "
		<< theState.GetName().c_str()
		<< std::endl;

spec << "void "
	<< myAdeStatechart->GetName().c_str()
	<< "_"
	<< theState.GetName().c_str()
	<< "("
	<< myAdeStatechart->GetName().c_str()
	<< "* me, "
	<< myAdeStatechart->GetEventType().c_str()
	<< "* theEvent);"
	<< std::endl;

impl << "void "
	<< myAdeStatechart->GetName().c_str()
	<< "_"
	<< theState.GetName().c_str()
	<< "("
	<< myAdeStatechart->GetName().c_str()
	<< "* me, "
	<< myAdeStatechart->GetEventType().c_str()
	<< "* theEvent)"
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

impl << "\treturn;" << std::endl;
impl << "}\n" << std::endl;
