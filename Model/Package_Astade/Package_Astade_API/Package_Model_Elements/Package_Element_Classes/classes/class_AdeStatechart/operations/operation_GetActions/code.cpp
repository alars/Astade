//~~ std::set<wxString> GetActions() [AdeStatechart] ~~

std::set<wxString> aSet;
std::set<wxString> retSet;
std::list<wxString> aList;

for (AdeElementIterator it = begin(); it != end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATE)
	{
		AdeState* aState = dynamic_cast<AdeState*>(anElement);
		aSet = aState->GetActions();
        retSet.insert(aSet.begin(), aSet.end());
	}
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = dynamic_cast<AdeTransition*>(anElement);
		aList = aTransition->GetActions();
		retSet.insert(aList.begin(), aList.end());
	}
	delete anElement;
}

aList = GetInitialActions();
retSet.insert(aList.begin(), aList.end());

return retSet;
