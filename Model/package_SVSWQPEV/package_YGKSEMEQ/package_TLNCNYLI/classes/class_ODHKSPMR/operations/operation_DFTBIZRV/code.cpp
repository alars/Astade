wxTreeItemId aID = myTree->GetSelection();
wxFileName destination = myTree->GetItem(aID)->GetFileName();

wxFileName source = myTree->GetItem(relationStart)->GetFileName();
wxFileName relations(source);

wxFileName theNewRelation = AdeRelation::CreateNewElement(source,destination);

relations.SetFullName("ModelNode.ini");
relations.AppendDir("relations");

myTree->SetItemHasChildren(relationStart);
wxTreeItemId relationsID = myTree->ShowNode(relations);

if (myTree->GetItem(relationsID)->GetFileName() != relations)
{
	wxTreeItemId newItem = myTree->AppendExistingItem(relationStart,relations);
	myTree->EnsureVisible(newItem);
	relationsID = myTree->ShowNode(relations);
}

myTree->AppendItem(relationsID, theNewRelation);

relationStart = wxTreeItemId();
AstadeClass::SetRelationSourceName(wxEmptyString);