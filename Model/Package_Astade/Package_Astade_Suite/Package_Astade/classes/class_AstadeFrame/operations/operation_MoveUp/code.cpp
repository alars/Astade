wxTreeItemId aID = myTree->GetSelection();

myTree->FixOrderValues(aID);

wxTreeItemId prevID = myTree->GetPrevSibling(aID);

if (prevID.IsOk())
{
	myTree->GetItem(aID)->SwapOrder(*(myTree->GetItem(prevID)));
	wxTreeItemId parent = myTree->GetItemParent(aID);
	myTree->SortChildren(parent);
	wxTreeItemId parentparent = myTree->GetItemParent(parent);
	myTree->UpdateItem(parentparent);
	myTree->GetItemObject(prevID)->Touch();
}
