//~~ void MoveUp(wxCommandEvent& event) [AstadeFrame] ~~

wxTreeItemId anID = myTree->GetSelection();

myTree->FixOrderValues(anID);

wxTreeItemId prevID = myTree->GetPrevSibling(anID);

if (prevID.IsOk())
{
	myTree->GetItem(anID)->SwapOrder(*(myTree->GetItem(prevID)));
	wxTreeItemId parent = myTree->GetItemParent(anID);
	myTree->SortChildren(parent);
	wxTreeItemId parentparent = myTree->GetItemParent(parent);
	myTree->UpdateItem(parentparent);
	myTree->GetItemObject(prevID)->Touch();
}
