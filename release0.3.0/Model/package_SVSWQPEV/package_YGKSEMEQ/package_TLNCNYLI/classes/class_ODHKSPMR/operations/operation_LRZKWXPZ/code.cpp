wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

AdeParameter::CreateNewElement(parentPath);
UpdateSubtree(aID);