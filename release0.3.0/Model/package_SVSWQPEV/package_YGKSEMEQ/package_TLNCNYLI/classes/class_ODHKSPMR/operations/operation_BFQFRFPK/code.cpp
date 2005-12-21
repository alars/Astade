wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

AdeClasses::CreateNewElement(parentPath);
UpdateSubtree(aID);