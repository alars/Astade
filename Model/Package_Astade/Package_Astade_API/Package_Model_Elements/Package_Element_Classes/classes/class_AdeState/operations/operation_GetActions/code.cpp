//~~ std::set<wxString> GetActions() [AdeState] ~~

std::list<wxString> aList;
std::set<wxString> retSet;

wxString aString;
aString = myConfig->Read(wxS("Astade/EntryAction"));
if (!aString.empty())
	retSet.insert(aString);

aString = myConfig->Read(wxS("Astade/ExitAction"));
if (!aString.empty())
	retSet.insert(aString);

for (AdeElementIterator it = begin(); it != end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = dynamic_cast<AdeTransition*>(anElement);
		aList = aTransition->GetActions();
		retSet.insert(aList.begin(), aList.end());
	}
	delete anElement;
}

return retSet;
