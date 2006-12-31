wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

wxFileName theNewStatechart = AdeStatechart::CreateNewElement(parentPath);
UpdateSubtree(aID);
myTree->ShowNode(theNewStatechart);