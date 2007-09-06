std::map<wxString, wxString> retVal;

std::set<wxString> baseClasses = GetBaseClasses();

if(!baseClasses.empty())
{
	for(std::set<wxString>::iterator it = baseClasses.begin(); it != baseClasses.end(); ++it)
	{
		AdeModelElement* aElement = AdeModelElement::CreateNewElement(*it);
		wxASSERT(aElement);

		AdeClass* aClass = dynamic_cast<AdeClass*>(aElement);
		wxASSERT(aClass);

		std::map<wxString, wxString> subOps = aClass->GetVirtualOperations();
		if (!subOps.empty())
			retVal.insert(subOps.begin(), subOps.end());

		delete(aElement);
	}
}


return retVal;