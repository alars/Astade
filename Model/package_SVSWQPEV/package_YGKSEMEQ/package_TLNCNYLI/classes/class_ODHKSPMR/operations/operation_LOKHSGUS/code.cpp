wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

wxTreeItemId newItem = myTree->AppendItem(aID,"new", 1);
myTree->SetItem(newItem,AdeComponents::CreateNewElement(parentPath));
myTree->UpdateItem(newItem);

myTree->SortChildren(aID);
