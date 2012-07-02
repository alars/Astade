//~~ void CodeStateFunction(AdeState& theState) [StateChartCoderVSM] ~~

wxString description(theState.GetDescription());
if (!description.empty())
{
	spec << "\n\t/** "
		<< description.utf8_str()
		<< std::endl;
	spec << "\t*/" << std::endl;
}
else
    spec << "\n\t//! @brief This is the state function for state "
		<< theState.GetName().utf8_str()
		<< std::endl;

spec << "\tvoid "
	<< theState.GetName().utf8_str()
	<< "("
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "& message);\n"
	<< std::endl;

impl << "void "
	<< myAdeStatechart->GetName().utf8_str()
	<< "::"
	<< theState.GetName().utf8_str()
	<< "("
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "& message)"
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

impl << "\t{" << std::endl;
impl << "\t\t// not handled" << std::endl;
impl << "\t\tmessage.NotHandeled();" << std::endl;
impl << "\t}" << std::endl;
impl << "\tEnterState(message);" << std::endl;
impl << "}\n" << std::endl;
