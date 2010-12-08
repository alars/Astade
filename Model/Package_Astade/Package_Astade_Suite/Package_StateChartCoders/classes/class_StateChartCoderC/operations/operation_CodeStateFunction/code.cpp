//~~ void CodeStateFunction(AdeState& theState) [StateChartCoderC] ~~

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

spec << "bool "
	<< myAdeStatechart->GetName().c_str()
	<< "_"
	<< theState.GetName().c_str()
	<< "("
	<< myAdeStatechart->GetName().c_str()
	<< "* me, const "
	<< myAdeStatechart->GetEventType().c_str()
	<< "* theEvent, "
	<< myAdeStatechart->GetName().c_str()
	<< "_eventIDs itsID);\n"
	<< std::endl;

impl << "bool "
	<< myAdeStatechart->GetName().c_str()
	<< "_"
	<< theState.GetName().c_str()
	<< "("
	<< myAdeStatechart->GetName().c_str()
	<< "* me, const "
	<< myAdeStatechart->GetEventType().c_str()
	<< "* theEvent, "
	<< myAdeStatechart->GetName().c_str()
	<< "_eventIDs itsID)"
	<< std::endl;
impl << "{" << std::endl;

AdeElementIterator it;
for (it = theState.begin(); it != theState.end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = static_cast<AdeTransition*>(anElement);
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
		AdeTransition* aTransition = static_cast<AdeTransition*>(anElement);
		if (aTransition->GetGuard().empty())
			CodeTransition(theState, *aTransition);
	}
	delete anElement;
}

impl << "\t// not handled" << std::endl;
impl << "\treturn false;" << std::endl;
impl << "}\n" << std::endl;
