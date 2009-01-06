wxTreeItemId aID = myTree->GetSelection();

AdeModelElement* aElement = myTree->GetItem(aID);
aElement->Rename();

wxTreeItemId pID = myTree->GetItemParent(aID);

myTree->SelectItem(pID);
myTree->Delete(aID);
myTree->AppendItem(pID,aElement->GetFileName());

// Update GUID cache:

wxConfigBase* theConfig = wxConfigBase::Get();
wxString modelPath = theConfig->Read("TreeView/ModelPath");

wxFileName modelDir;
modelDir.AssignDir(modelPath);
modelDir.MakeAbsolute();

AdeModel* aModel = new AdeModel(modelDir);

AdeGUIDCache::Instance()->Load(*aModel);
delete aModel;
