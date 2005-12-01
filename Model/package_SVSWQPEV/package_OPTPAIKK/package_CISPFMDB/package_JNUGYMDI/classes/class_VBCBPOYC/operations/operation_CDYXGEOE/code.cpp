std::set<wxString> aSet;
std::set<wxString> retSet;

wxString aString;

wxFileConfig theConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());

aString = theConfig.Read("Astade/EntryAction");
if (!aString.empty())
	retSet.insert(aString);

aString = theConfig.Read("Astade/ExitAction");
if (!aString.empty())
	retSet.insert(aString);

AdeElementIterator it;
for (it=begin();it!=end();++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	if ((aElement->GetType() & 0x7F00000) == ITEM_IS_TRANSITION)
	{
		AdeTransition* aTransition = static_cast<AdeTransition*>(aElement);
		aSet = aTransition->GetActions();
		for (std::set<wxString>::iterator iter=aSet.begin();iter!=aSet.end();iter++)
			retSet.insert(*iter);
	}
	delete aElement;
}

return retSet;