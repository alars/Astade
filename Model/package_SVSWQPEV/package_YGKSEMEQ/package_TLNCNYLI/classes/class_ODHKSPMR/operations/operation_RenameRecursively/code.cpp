wxTreeItemId aID = myTree->GetSelection();
wxTreeItemId pID = myTree->GetItemParent(aID);

AdeModelElement* anElement = myTree->GetItem(aID);
anElement->RenameRecursively();
wxFileName newFilename = anElement->GetFileName();

myTree->SelectItem(pID);
myTree->Delete(aID);
myTree->AppendItem(pID, newFilename);

// Update GUID cache:

wxConfigBase* theConfig = wxConfigBase::Get();
wxString modelPath = theConfig->Read("TreeView/ModelPath");

wxFileName modelDir;
modelDir.AssignDir(modelPath);
modelDir.MakeAbsolute();

AdeModel* aModel = new AdeModel(modelDir);

AdeGUIDCache::Instance()->Load(*aModel);
delete aModel;
