std::set<wxString> aSet;
std::set<wxString> retSet;

AdeElementIterator it;
for (it=begin();it!=end();++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & 0x7F00000) == ITEM_IS_STATE)
	{
		AdeState* aState = static_cast<AdeState*>(aElement);
		aSet = aState->GetGuards();
		for (std::set<wxString>::iterator iter=aSet.begin();iter!=aSet.end();iter++)
			retSet.insert(*iter);
	}
	delete aElement;
}

return retSet;