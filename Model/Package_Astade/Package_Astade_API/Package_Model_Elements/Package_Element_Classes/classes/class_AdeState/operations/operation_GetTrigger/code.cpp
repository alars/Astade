//~~ std::set<wxString> GetTrigger() [AdeState] ~~

std::set<wxString> retSet;
for (AdeElementIterator it = begin(); it != end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = dynamic_cast<AdeTransition*>(anElement);
		wxString aString = aTransition->GetTrigger();
		if (!aString.empty())
			retSet.insert(aString);
	}
	delete anElement;
}

return retSet;
