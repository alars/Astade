wxTreeItemId aID = myTree->GetSelection();
wxFileName destination = myTree->GetItem(aID)->GetFileName();

wxFileName source = myTree->GetItem(RelationStart)->GetFileName();

AdeRelation::CreateNewElement(source,destination);
UpdateSubtree(aID);
UpdateSubtree(RelationStart);

RelationStart = wxTreeItemId();
