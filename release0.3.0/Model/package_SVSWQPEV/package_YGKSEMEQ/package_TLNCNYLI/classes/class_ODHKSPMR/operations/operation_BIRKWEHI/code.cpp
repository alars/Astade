wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

AdeClass::CreateNewElement(parentPath);
UpdateSubtree(aID);