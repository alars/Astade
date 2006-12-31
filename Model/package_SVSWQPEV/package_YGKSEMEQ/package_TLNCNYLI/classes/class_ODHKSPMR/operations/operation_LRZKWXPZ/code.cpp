wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

wxFileName theNewParameter = AdeParameter::CreateNewElement(parentPath);
UpdateSubtree(aID);
myTree->ShowNode(theNewParameter);