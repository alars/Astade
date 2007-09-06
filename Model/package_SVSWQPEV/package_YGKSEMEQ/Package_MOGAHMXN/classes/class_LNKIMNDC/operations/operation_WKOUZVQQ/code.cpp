if((menuId<ID_OVERLOADMIN) || (menuId>ID_OVERLOADMAX))
{
	wxASSERT_MSG(false, "AstadeOperations::OverloadOperation(): id out of range!");
	return wxFileName();
}

// search cache for index
std::map<int, wxString>::iterator it = overloadIDs.find(menuId);
if(it==overloadIDs.end())
{
	wxASSERT_MSG(false, "AstadeOperations::OverloadOperation(): id not found!");
	return wxFileName();
}

// get AdeOperation from cached filename
AdeOperation* aOperation = dynamic_cast<AdeOperation*>(AdeModelElement::CreateNewElement(it->second));

wxASSERT_MSG(aOperation, "AstadeOperations::OverloadOperation(): target file is not a AdeOperation!");

return aOperation->CreateCopy(myModelElement->GetFileName());
