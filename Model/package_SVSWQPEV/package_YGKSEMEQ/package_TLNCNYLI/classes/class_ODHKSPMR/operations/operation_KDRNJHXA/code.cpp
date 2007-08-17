wxTreeItemId aID = myTree->GetSelection();

AdeModelElement* aElement = myTree->GetItem(aID);

if (aElement->GetHasChildren())
{
	wxMessageDialog aDialog(this,"Element is not empty, delete anyway?","Delete:",wxOK | wxCANCEL | wxICON_EXCLAMATION );
	if (aDialog.ShowModal()==wxID_CANCEL)
		return;
}

aElement->Delete();

wxTreeItemId parentID = myTree->GetItemParent(aID);

wxTreeItemId newID = myTree->GetPrevSibling(aID);

if (!newID.IsOk())
	newID = myTree->GetNextSibling(aID);

if (!newID.IsOk())
	newID = myTree->GetItemParent(aID);

myTree->SelectItem(newID);
myTree->Delete(aID);

aElement = myTree->GetItem(parentID);
aElement->Touch();

while (parentID.IsOk())
{
	myTree->UpdateItem(parentID);
	parentID = myTree->GetItemParent(parentID);
}
