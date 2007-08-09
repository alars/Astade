wxTreeItemId aID = myTree->GetSelection();
wxFileName destination = myTree->GetItem(aID)->GetFileName();

wxFileName source = myTree->GetItem(relationStart)->GetFileName();

wxFileName theNewRelation = AdeRelation::CreateNewElement(source,destination);

UpdateSubtree(relationStart);
UpdateSubtree(aID);

relationStart = wxTreeItemId();
AstadeClass::SetRelationSourceName(wxEmptyString);

myTree->ShowNode(theNewRelation);