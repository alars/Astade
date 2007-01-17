wxTreeItemId aID = myTree->GetRootItem();
myTree->Collapse(aID);

AdeModel* model = dynamic_cast<AdeModel*>(myTree->GetItem(aID));

if (model)
{
	ScanForRename(*model);
	AdeGUIDCache::Instance()->Load(*model);
	wxLogMessage("Renaming done!");
}