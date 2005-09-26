wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

AdeAttribute::CreateNewElement(parentPath);
UpdateSubtree(aID);