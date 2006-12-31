wxTreeItemId aID = myTree->GetSelection();
wxFileName destination = myTree->GetItem(aID)->GetFileName();

wxFileName source = myTree->GetItem(RelationStart)->GetFileName();

wxFileName theNewRelation = AdeRelation::CreateNewElement(source,destination);

UpdateSubtree(RelationStart);
UpdateSubtree(aID);

RelationStart = wxTreeItemId();
myTree->ShowNode(theNewRelation);