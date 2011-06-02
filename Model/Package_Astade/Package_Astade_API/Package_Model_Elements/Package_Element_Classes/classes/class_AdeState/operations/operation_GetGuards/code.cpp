//~~ std::set<wxString> GetGuards() [AdeState] ~~

std::set<wxString> retSet;
for (AdeElementIterator it = begin(); it != end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = dynamic_cast<AdeTransition*>(anElement);
		wxString aString = aTransition->GetGuard();
		if (!aString.empty())
        {
            aString.Replace("!", ""); // if someone uses "not" in a guard, its still the same guard
			retSet.insert(aString);
        }
	}
	delete anElement;
}

return retSet;
