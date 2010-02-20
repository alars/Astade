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

std::list<wxString> aList = GetInitialActions();
for (std::list<wxString>::iterator iter = aList.begin(); iter != aList.end(); ++iter)
	retSet.insert(*iter);

return retSet;
