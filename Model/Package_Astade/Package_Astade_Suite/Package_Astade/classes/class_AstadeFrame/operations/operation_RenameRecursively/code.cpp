//~~ void RenameRecursively(wxCommandEvent& event) [AstadeFrame] ~~

wxTreeItemId anID = myTree->GetSelection();
wxTreeItemId pID = myTree->GetItemParent(anID);

AdeModelElement* anElement = myTree->GetItem(anID);
anElement->RenameRecursively();
wxFileName newFilename = anElement->GetFileName();

myTree->SelectItem(pID);
myTree->Delete(anID);
myTree->AppendItem(pID, newFilename);

// Update GUID cache:

wxConfigBase* theConfig = wxConfigBase::Get();
wxString modelPath = theConfig->Read(wxS("TreeView/ModelPath"));

wxFileName modelDir;
modelDir.AssignDir(modelPath);
modelDir.MakeAbsolute();

AdeModel* aModel = new AdeModel(modelDir);

AdeGUIDCache::Instance()->Load(*aModel);
delete aModel;
