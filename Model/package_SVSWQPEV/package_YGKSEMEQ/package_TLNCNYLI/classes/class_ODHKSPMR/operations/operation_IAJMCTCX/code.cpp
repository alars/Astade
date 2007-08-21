wxTreeItemId aID = myTree->GetSelection();

if (!aID.IsOk())
	return;

wxFileName theNewElement = myTree->GetItemObject(aID)->AddSubElement(event.GetId());

AdeModelElement* aElement = AdeModelElement::CreateNewElement(theNewElement);

if (myTree->GetChildrenCount(aID) > 0)
{
	wxTreeItemId newItem = myTree->AppendItem(aID,"loading ...", 48);
	myTree->EnsureVisible(newItem);
	myTree->SetItem(newItem,aElement);
	myTree->GetItemObject(newItem)->Touch();
	myTree->SelectItem(newItem);
}
else
{
	myTree->GetItemObject(aID)->Touch();
	myTree->ShowNode(theNewElement);
}