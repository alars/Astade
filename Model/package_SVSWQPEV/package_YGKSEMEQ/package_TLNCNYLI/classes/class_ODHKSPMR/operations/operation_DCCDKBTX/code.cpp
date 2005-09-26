wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

AdeParameters::CreateNewElement(parentPath);
UpdateSubtree(aID);