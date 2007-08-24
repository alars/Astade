std::map<wxString, wxString> retVal;

printf("GetOverloadableOperations for class %s\n", GetLabel().c_str());

std::set<wxString> baseClasses = GetBaseClasses();

if(!baseClasses.empty())
{
	std::set<wxString>::iterator it;
	for(it=baseClasses.begin(); it!=baseClasses.end(); ++it)
	{
		printf("Process file: %s\n", it->c_str());
		AdeModelElement* aElement = AdeModelElement::CreateNewElement(*it);
		wxASSERT(aElement);

		AdeClass* aClass = dynamic_cast<AdeClass*>(aElement);
		wxASSERT(aClass);

		std::map<wxString, wxString> subOps = aClass->GetVirtualOperations();
		retVal.insert(subOps.begin(), subOps.end());

		delete(aElement);
	}
}


return retVal;