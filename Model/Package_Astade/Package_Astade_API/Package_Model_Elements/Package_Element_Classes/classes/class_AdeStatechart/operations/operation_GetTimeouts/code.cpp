//~~ std::set<wxString> GetTimeouts() [AdeStatechart] ~~

std::set<wxString> retSet;
for (AdeElementIterator it = begin(); it != end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATE)
	{
		AdeState* aState = dynamic_cast<AdeState*>(anElement);
		wxString aString = aState->GetTimeout();
		long dummy;
		if (!aString.empty() && !aString.ToLong(&dummy))
			retSet.insert(retSet.begin(),aState->GetTimeout());
	}
	delete anElement;
}

return retSet;
