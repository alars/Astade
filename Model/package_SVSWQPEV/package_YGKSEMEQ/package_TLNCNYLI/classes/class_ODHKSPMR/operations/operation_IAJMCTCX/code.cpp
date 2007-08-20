wxTreeItemId aID = myTree->GetSelection();

if (!aID.IsOk())
	return;

wxFileName theNewElement = myTree->GetItemObject(aID)->AddSubElement(event.GetId());

AdeModelElement* aElement = AdeModelElement::CreateNewElement(theNewElement);

wxTreeItemId newItem = myTree->AppendItem(aID,"loading ...", 48);
myTree->SetItem(newItem,aElement);

myTree->SetItemHasChildren(aID);
myTree->SelectItem(newItem);
myTree->EnsureVisible(newItem);

while (newItem.IsOk())
{
	myTree->UpdateItem(newItem);
	myTree->GetItem(newItem)->Touch();
	newItem = myTree->GetItemParent(newItem);
}