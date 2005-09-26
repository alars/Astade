wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

AdeRelations::CreateNewElement(parentPath);
UpdateSubtree(aID);