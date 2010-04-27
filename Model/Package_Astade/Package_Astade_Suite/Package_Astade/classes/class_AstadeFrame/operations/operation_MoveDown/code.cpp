wxTreeItemId aID = myTree->GetSelection();

myTree->FixOrderValues(aID);

wxTreeItemId nextID = myTree->GetNextSibling(aID);

if (nextID.IsOk())
{
	myTree->GetItem(aID)->SwapOrder(*(myTree->GetItem(nextID)));
	wxTreeItemId parent = myTree->GetItemParent(aID);
	myTree->SortChildren(parent);
	wxTreeItemId parentparent = myTree->GetItemParent(parent);
	myTree->UpdateItem(parentparent);
	myTree->GetItemObject(nextID)->Touch();
}
