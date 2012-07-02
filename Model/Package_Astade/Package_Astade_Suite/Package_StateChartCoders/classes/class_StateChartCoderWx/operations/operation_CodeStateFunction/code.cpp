//~~ void CodeStateFunction(AdeState& theState) [StateChartCoderWx] ~~

wxString description(theState.GetDescription());
if (!description.empty())
{
	spec << "/** "
		<< description.utf8_str()
		<< std::endl;
	spec << "*/" << std::endl;
}
else
    spec << "\t//! @brief This is the state function for state "
		<< theState.GetName().utf8_str()
		<< std::endl;

spec << "\tbool "
	<< theState.GetName().utf8_str()
	<< "("
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "& theEvent);\n"
	<< std::endl;

impl << "bool "
	<< myAdeStatechart->GetName().utf8_str()
	<< "::"
	<< theState.GetName().utf8_str()
	<< "("
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "& theEvent)"
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
