//~~ std::set<wxString> GetGuards() [AdeStatechart] ~~

std::set<wxString> aSet;
std::set<wxString> retSet;

for (AdeElementIterator it = begin(); it != end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATE)
	{
		AdeState* aState = dynamic_cast<AdeState*>(anElement);
		aSet = aState->GetGuards();
		for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); ++iter)
			retSet.insert(*iter);
	}
	delete anElement;
}

return retSet;
