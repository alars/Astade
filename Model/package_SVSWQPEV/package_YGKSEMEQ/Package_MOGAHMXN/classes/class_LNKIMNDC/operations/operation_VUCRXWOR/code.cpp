wxMenu* aSubUp = new wxMenu(wxEmptyString);

/*
overloadIDs.clear(); // clear cache

AdeClass* parentClass = dynamic_cast<AdeClass*>(myModelElement->GetParent());
wxASSERT_MSG(parentClass, "AstadeOperations::CreateOverloadMenu(): Parent is not a AdeClass!");

std::map<wxString, wxString> ops = parentClass->GetOverloadableOperations();

delete(parentClass);

std::map<wxString, wxString>::iterator it;

int id = 0;
for(it=ops.begin(); it!=ops.end(); ++it)
{
	aSubUp->Append(ID_OVERLOADMIN+id, it->first, wxEmptyString, wxITEM_NORMAL);
	overloadIDs[id] = it->second;
	id++;

	if(id>=(ID_OVERLOADMAX-ID_OVERLOADMIN)) break;
}
*/
return aSubUp;
