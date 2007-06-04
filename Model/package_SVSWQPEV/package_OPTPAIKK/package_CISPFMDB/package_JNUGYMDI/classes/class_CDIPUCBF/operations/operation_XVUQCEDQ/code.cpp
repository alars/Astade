std::set<wxString> retSet;

AdeElementIterator it;
for (it = begin(); it != end(); ++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATE)
	{
		AdeState* aState = dynamic_cast<AdeState*>(aElement);
		wxString aString = aState->GetTimeout();
		long dummy;
		if (!aString.empty() && !aString.ToLong(&dummy))
			retSet.insert(retSet.begin(),aState->GetTimeout());
	}
	delete aElement;
}

return retSet;
