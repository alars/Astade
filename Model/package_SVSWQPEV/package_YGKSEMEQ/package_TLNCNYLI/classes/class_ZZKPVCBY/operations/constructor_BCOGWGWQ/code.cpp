SetImageList(&myIcons);
wxTreeItemId myRootItem = AddRoot("model", 1);

wxConfigBase* theConfig = wxConfigBase::Get();
wxString modelPath = theConfig->Read("TreeView/ModelPath");

wxFileName modelDir;
modelDir.AssignDir(modelPath);
modelDir.MakeAbsolute();

AdeModel* aModel = new AdeModel(modelDir);
SetItemData(myRootItem, aModel);

if (aModel->GetRepository() == "SVN")
	AdeRevisionControlBase::SetRevisionControlObject(new AdeRevisionControlSVN);
else if (aModel->GetRepository() == "git")
	AdeRevisionControlBase::SetRevisionControlObject(new AdeRevisionControlGIT);
else
	AdeRevisionControlBase::SetRevisionControlObject(new AdeRevisionControlNone);

UpdateItem(myRootItem);
