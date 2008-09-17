wxTreeItemId aID = myTree->GetSelection();

AdeModelElement* anElement = myTree->GetItem(aID);

if (anElement->HasChildren())
{
	wxMessageDialog aDialog(this,"Element is not empty, delete anyway?","Delete:",wxOK | wxCANCEL | wxICON_EXCLAMATION );
	if (aDialog.ShowModal() == wxID_CANCEL)
		return;
}

anElement->Delete();

wxTreeItemId parentID = myTree->GetItemParent(aID);

wxTreeItemId newID = myTree->GetPrevSibling(aID);

if (!newID.IsOk())
	newID = myTree->GetNextSibling(aID);

if (!newID.IsOk())
	newID = myTree->GetItemParent(aID);

myTree->SelectItem(newID);
myTree->Delete(aID);

myTree->GetItemObject(parentID)->Touch();
