std::list<wxString> aList;
std::set<wxString> retSet;

wxString aString;

aString = myConfig->Read(wxS("Astade/EntryAction"));
if (!aString.empty())
	retSet.insert(aString);

aString = myConfig->Read(wxS("Astade/ExitAction"));
if (!aString.empty())
	retSet.insert(aString);

AdeElementIterator it;
for (it = begin(); it != end(); ++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = dynamic_cast<AdeTransition*>(aElement);
		aList = aTransition->GetActions();
		for (std::list<wxString>::iterator iter = aList.begin(); iter != aList.end(); ++iter)
			retSet.insert(*iter);
	}
	delete aElement;
}

return retSet;
