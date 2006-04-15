SetImageList(&myIcons);
wxTreeItemId myRootItem = AddRoot("model",1);

wxConfigBase* theConfig = wxConfigBase::Get();
wxString modelPath = theConfig->Read("TreeView/ModelPath");

wxFileName modelDir;
modelDir.AssignDir(modelPath);
modelDir.MakeAbsolute();

AdeModelElement* aModel=new AdeModel(modelDir);
SetItemData(myRootItem,aModel);

UpdateItem(myRootItem);