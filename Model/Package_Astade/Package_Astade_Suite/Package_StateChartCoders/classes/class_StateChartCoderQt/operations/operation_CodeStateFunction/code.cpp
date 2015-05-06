//~~ void CodeStateFunction(AdeState& theState, AdeStatechart& theStatechart) [StateChartCoderQt] ~~

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
	<< "(const AQF_MessageReceiver* port, const "
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "& theEvent);\n"
	<< std::endl;

impl << "void "
	<< myAdeStatechart->GetName().utf8_str()
	<< "::"
	<< theState.GetName().utf8_str()
	<< "(const AQF_MessageReceiver* port, const "
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "& theEvent)"
	<< std::endl;
impl << "{" << std::endl;
impl << "\tQ_UNUSED(port)" << std::endl;
impl << "\tQ_UNUSED(theEvent)" << std::endl;

AdeElementIterator it;

for (it = theState.begin(); it != theState.end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = dynamic_cast<AdeTransition*>(anElement);
		if (!aTransition->GetGuard().empty() && !aTransition->IsAllTransition())
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
		if (aTransition->GetGuard().empty() && !aTransition->IsAllTransition())
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
		if (!aTransition->GetGuard().empty() && aTransition->IsAllTransition())
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
		if (aTransition->GetGuard().empty() && aTransition->IsAllTransition())
			CodeTransition(theState, *aTransition);
	}
	delete anElement;
}

//************************

for (it = theStatechart.begin(); it != theStatechart.end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = dynamic_cast<AdeTransition*>(anElement);
		if (!aTransition->GetGuard().empty() && !aTransition->IsAllTransition())
			CodeTransition(theState, *aTransition);
	}
	delete anElement;
}

for (it = theStatechart.begin(); it != theStatechart.end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = dynamic_cast<AdeTransition*>(anElement);
		if (aTransition->GetGuard().empty() && !aTransition->IsAllTransition())
			CodeTransition(theState, *aTransition);
	}
	delete anElement;
}

for (it = theStatechart.begin(); it != theStatechart.end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = dynamic_cast<AdeTransition*>(anElement);
		if (!aTransition->GetGuard().empty() && aTransition->IsAllTransition())
			CodeTransition(theState, *aTransition);
	}
	delete anElement;
}

for (it = theStatechart.begin(); it != theStatechart.end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = dynamic_cast<AdeTransition*>(anElement);
		if (aTransition->GetGuard().empty() && aTransition->IsAllTransition())
			CodeTransition(theState, *aTransition);
	}
	delete anElement;
}


impl << "\treturn;" << std::endl;
impl << "}\n" << std::endl;
