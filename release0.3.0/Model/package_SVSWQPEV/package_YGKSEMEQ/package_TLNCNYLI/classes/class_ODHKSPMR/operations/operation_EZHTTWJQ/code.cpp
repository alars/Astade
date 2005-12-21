wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

AdeAttributes::CreateNewElement(parentPath);
UpdateSubtree(aID);