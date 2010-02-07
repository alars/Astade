wxMenu* aSubUp = new wxMenu(wxEmptyString);

overloadIDs.clear(); // clear cache

AdeClass* parentClass = dynamic_cast<AdeClass*>(myModelElement->GetParent());
wxASSERT_MSG(parentClass, "AstadeOperations::CreateOverloadMenu(): Parent is not a AdeClass!");

std::map<wxString, wxString> ops = parentClass->GetOverloadableOperations();

delete(parentClass);

std::set<wxString> alreadyOverloaded;

for (AdeElementIterator it = dynamic_cast<AdeOperations*>(myModelElement)->begin(); it != dynamic_cast<AdeOperations*>(myModelElement)->end(); ++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	AdeOperationBase* aOperation = dynamic_cast<AdeOperationBase*>(aElement);
	if (aOperation)
		alreadyOverloaded.insert(alreadyOverloaded.begin(),aOperation->GetSignature());
	delete aElement;
}

int id;
std::map<wxString, wxString>::iterator it;
for(it=ops.begin(), id = ID_OVERLOADMIN; it!=ops.end() && id <= ID_OVERLOADMAX;	++it, id++)
{
	aSubUp->Append(id, (*it).first, wxEmptyString, wxITEM_NORMAL);
	overloadIDs[id] = (*it).second;
	aSubUp->Enable(id,alreadyOverloaded.find((*it).first) == alreadyOverloaded.end());
	if (((*it).first.find("~")==0) && (static_cast<AdeDirectoryElement*>(myModelElement)->HasDestructor()))
		aSubUp->Enable(id,false);
}

return aSubUp;
