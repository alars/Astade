//~~ wxMenu* CreateOverloadMenu() [AstadeOperations] ~~

wxMenu* aSubUp = new wxMenu(wxEmptyString);

overloadIDs.clear(); // clear cache

AdeClass* parentClass = dynamic_cast<AdeClass*>(myModelElement->GetParent());
wxASSERT_MSG(parentClass, "AstadeOperations::CreateOverloadMenu(): Parent is not an AdeClass!");

std::map<wxString, wxString> ops = parentClass->GetOverloadableOperations();

delete parentClass;

std::set<wxString> alreadyOverloaded;

for (AdeElementIterator it = dynamic_cast<AdeOperations*>(myModelElement)->begin(); it != dynamic_cast<AdeOperations*>(myModelElement)->end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	AdeOperationBase* anOperation = dynamic_cast<AdeOperationBase*>(anElement);
	if (anOperation)
		alreadyOverloaded.insert(alreadyOverloaded.begin(), anOperation->GetSignature());
	delete anElement;
}

int id;
std::map<wxString, wxString>::iterator it;
for (it = ops.begin(), id = ID_OVERLOADMIN; it != ops.end() && id <= ID_OVERLOADMAX; ++it, ++id)
{
	wxString item(it->first);
	item.Replace(wxS("&"), wxS("&&"), true);
	aSubUp->Append(id, item, wxEmptyString, wxITEM_NORMAL);

	if (it->second.EndsWith(wxS(".ini")))
		overloadIDs[id] = it->second;
	else
		overloadIDs[id] = wxS(":") + it->second + wxS(":") + it->first;
	aSubUp->Enable(id, alreadyOverloaded.find(it->first) == alreadyOverloaded.end());
	if (it->first.find(wxS("~")) == 0 && static_cast<AdeDirectoryElement*>(myModelElement)->HasDestructor())
		aSubUp->Enable(id, false);
}

return aSubUp;
