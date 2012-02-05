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
			// if someone uses "not" in a guard, it's still the same guard
            aString.Replace(wxS("!"), wxEmptyString);
			retSet.insert(aString);
        }
	}
	delete anElement;
}

return retSet;
