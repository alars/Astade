wxTreeItemId aID = myTree->GetSelection();
wxFileName destination = myTree->GetItem(aID)->GetFileName();


AdeModelElement* aElement = myTree->GetItem(copySource);

wxFileName parentPath;
parentPath.AssignDir(destination.GetPath());

aElement->CreateCopy(parentPath);
UpdateSubtree(aID);