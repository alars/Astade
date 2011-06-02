//~~ void MoveDown(wxCommandEvent& event) [AstadeFrame] ~~

wxTreeItemId anID = myTree->GetSelection();

myTree->FixOrderValues(anID);

wxTreeItemId nextID = myTree->GetNextSibling(anID);

if (nextID.IsOk())
{
	myTree->GetItem(anID)->SwapOrder(*(myTree->GetItem(nextID)));
	wxTreeItemId parent = myTree->GetItemParent(anID);
	myTree->SortChildren(parent);
	wxTreeItemId parentparent = myTree->GetItemParent(parent);
	myTree->UpdateItem(parentparent);
	myTree->GetItemObject(nextID)->Touch();
}
