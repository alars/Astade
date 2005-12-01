std::set<wxString> retSet;

AdeElementIterator it;
for (it=begin();it!=end();++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & 0x7F00000) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = static_cast<AdeTransition*>(aElement);
		wxString aString = aTransition->GetGuard();
		if (!aString.empty())
			retSet.insert(aString);
	}
	delete aElement;
}

return retSet;