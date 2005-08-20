SetImageList(&myIcons);
myRootItem = AddRoot("model",1);

wxConfigBase* theConfig = wxConfigBase::Get();
wxString modelPath = theConfig->Read("TreeView/ModelPath");

AdeModelElement* aModel=new AdeModel(modelPath);
SetItemData(myRootItem,aModel);

UpdateItem(myRootItem);
