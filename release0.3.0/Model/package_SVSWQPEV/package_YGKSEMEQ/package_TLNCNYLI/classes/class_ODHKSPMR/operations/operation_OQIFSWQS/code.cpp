wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

AdeTypes::CreateNewElement(parentPath);
UpdateSubtree(aID);