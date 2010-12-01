//~~ std::set<wxString> GetActions() [AdeStatechart] ~~

std::set<wxString> aSet;
std::set<wxString> retSet;

for (AdeElementIterator it = begin(); it != end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATE)
	{
		AdeState* aState = dynamic_cast<AdeState*>(anElement);
		aSet = aState->GetActions();
		for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); ++iter)
			retSet.insert(*iter);
	}
	delete anElement;
}

std::list<wxString> aList = GetInitialActions();
for (std::list<wxString>::iterator iter = aList.begin(); iter != aList.end(); ++iter)
	retSet.insert(*iter);

return retSet;
