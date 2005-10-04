wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

AdeDestructor::CreateNewElement(parentPath);
UpdateSubtree(aID);
