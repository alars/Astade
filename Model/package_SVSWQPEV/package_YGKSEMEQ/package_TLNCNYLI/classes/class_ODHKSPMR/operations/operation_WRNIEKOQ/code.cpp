wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

if (myTree->IsExpanded(aID))
	myTree->Collapse(aID);

AdeConfiguration::CreateNewElement(parentPath);
myTree->UpdateItem(aID);

myTree->SetItemHasChildren(aID,true);
myTree->Expand(aID);
myTree->SortChildren(aID);