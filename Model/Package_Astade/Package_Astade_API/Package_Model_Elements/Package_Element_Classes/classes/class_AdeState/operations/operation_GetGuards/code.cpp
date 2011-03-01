//~~ std::set<wxString> GetGuards() [AdeState] ~~
std::set<wxString> retSet;

AdeElementIterator it;
for (it = begin(); it != end(); ++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = dynamic_cast<AdeTransition*>(aElement);
		wxString aString = aTransition->GetGuard();
		if (!aString.empty())
        {
            aString.Replace("!",""); // if someone uses "not" in a guard, its still the same guard
			retSet.insert(aString);
        }
	}
	delete aElement;
}

return retSet;
