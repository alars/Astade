wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

AdeConfiguration::CreateNewElement(parentPath);
UpdateSubtree(aID);