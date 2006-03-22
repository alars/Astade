std::set<wxString> aSet;
std::set<wxString> retSet;

AdeElementIterator it;
for (it = begin(); it != end(); ++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATE)
	{
		AdeState* aState = dynamic_cast<AdeState*>(aElement);
		aSet = aState->GetActions();
		for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); ++iter)
			retSet.insert(*iter);
	}
	delete aElement;
}

aSet = GetInitialActions();
for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); ++iter)
	retSet.insert(*iter);

return retSet;
