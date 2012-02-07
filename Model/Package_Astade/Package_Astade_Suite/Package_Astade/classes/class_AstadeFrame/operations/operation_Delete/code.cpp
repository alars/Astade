//~~ void Delete(wxCommandEvent& event) [AstadeFrame] ~~

wxTreeItemId anID = myTree->GetSelection();

AdeModelElement* anElement = myTree->GetItem(anID);

if (anElement->HasChildren())
{
	wxMessageDialog aDialog(this, wxS("Element is not empty, delete anyway?"), wxS("Delete:"), wxOK | wxCANCEL | wxICON_EXCLAMATION );
	if (aDialog.ShowModal() == wxID_CANCEL)
		return;
}

AdeClass* theClass = dynamic_cast<AdeClass*>(anElement);
if (theClass)
{
	// we're deleting a class - remove it from all components first
	for (AdeElementIterator it = theClass->GetFirstComponent();
		it != theClass->end(); ++it)
	{
		AdeModelElement* nextElement = it.CreateNewElement();
		AdeComponent* nextComponent = dynamic_cast<AdeComponent*>(nextElement);
		if (nextComponent)
			nextComponent->RemoveFromComponent(*theClass);
		delete nextElement;
	}
}

anElement->Delete();

wxTreeItemId parentID = myTree->GetItemParent(anID);

wxTreeItemId newID = myTree->GetPrevSibling(anID);

if (!newID.IsOk())
	newID = myTree->GetNextSibling(anID);

if (!newID.IsOk())
	newID = myTree->GetItemParent(anID);

myTree->SelectItem(newID);
myTree->Delete(anID);

myTree->GetItemObject(parentID)->Touch();
