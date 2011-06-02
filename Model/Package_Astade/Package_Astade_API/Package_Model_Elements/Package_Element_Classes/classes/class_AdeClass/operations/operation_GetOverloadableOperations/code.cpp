//~~ std::map<wxString, wxString> GetOverloadableOperations() [AdeClass] ~~

std::map<wxString, wxString> retVal;
std::set<wxString> baseClasses = GetBaseClasses();

if (!baseClasses.empty())
{
	for (std::set<wxString>::iterator it = baseClasses.begin(); it != baseClasses.end(); ++it)
	{
		AdeModelElement* anElement = AdeModelElement::CreateNewElement(*it);
		wxASSERT(anElement);

		AdeClass* aClass = dynamic_cast<AdeClass*>(anElement);
		wxASSERT(aClass);

		std::map<wxString, wxString> subOps = aClass->GetVirtualOperations();
		if (!subOps.empty())
			retVal.insert(subOps.begin(), subOps.end());

		delete anElement;
	}
}

return retVal;
