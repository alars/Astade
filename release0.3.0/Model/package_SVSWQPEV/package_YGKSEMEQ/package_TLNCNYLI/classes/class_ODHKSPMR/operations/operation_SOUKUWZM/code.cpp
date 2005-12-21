if (myTree->IsExpanded(aID))
	myTree->Collapse(aID);

myTree->SetItemHasChildren(aID,true);
myTree->Expand(aID);
myTree->SortChildren(aID);

while (aID.IsOk())
{
	myTree->DoUpdateItem(aID);
	aID = myTree->GetItemParent(aID);
}
