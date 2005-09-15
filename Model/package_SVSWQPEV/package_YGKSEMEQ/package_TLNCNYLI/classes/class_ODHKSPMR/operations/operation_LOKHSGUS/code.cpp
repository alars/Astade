wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

if (myTree->IsExpanded(aID))
{
	wxTreeItemId newItem = myTree->AppendItem(aID,"new", 1);
	myTree->SetItem(newItem,AdeComponents::CreateNewElement(parentPath));
	myTree->UpdateItem(aID);
	myTree->UpdateItem(newItem);
}
else
{
	delete AdeComponents::CreateNewElement(parentPath);
	myTree->UpdateItem(aID);
	myTree->Expand(aID);
}

myTree->SortChildren(aID);
