wxTreeItemId aID = event.GetItem();
AdeDirectoryElement* aDir = static_cast<AdeDirectoryElement*>(myTree->GetItem(aID));

if (aDir->begin() != aDir->end())
{
	wxTreeItemId newItem = myTree->AppendItem(aID,"new", 1);
	myTree->SetItem(newItem,*(aDir->begin()));
	myTree->UpdateItem(newItem);
}