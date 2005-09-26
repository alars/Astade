wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

AdeOperations::CreateNewElement(parentPath);
UpdateSubtree(aID);