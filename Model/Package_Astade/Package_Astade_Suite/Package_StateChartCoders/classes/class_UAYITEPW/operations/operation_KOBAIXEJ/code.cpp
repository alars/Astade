//~~ void CodeStateFunction(AdeState& theState) [StateChartCoderACF] ~~

wxString description(theState.GetDescription());
if (!description.empty())
{
	spec << "/** "
		<< description.utf8_str()
		<< std::endl;
	spec << "*/" << std::endl;
}
else
    spec << "//! @brief This is the state function for state "
		<< theState.GetName().utf8_str()
		<< std::endl;

spec << "void "
	<< myAdeStatechart->GetName().utf8_str()
	<< "_"
	<< theState.GetName().utf8_str()
	<< "("
	<< myAdeStatechart->GetName().utf8_str()
	<< "* me, "
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "* theEvent);"
	<< std::endl;

impl << "void "
	<< myAdeStatechart->GetName().utf8_str()
	<< "_"
	<< theState.GetName().utf8_str()
	<< "("
	<< myAdeStatechart->GetName().utf8_str()
	<< "* me, "
	<< myAdeStatechart->GetEventType().utf8_str()
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
