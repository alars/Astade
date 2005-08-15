SetImageList(&myIcons);
myRootItem = AddRoot("model",5);

AdeModelElement* aModel=new AdeModel;
AstadeConfigDialog* aDialog = new AstadeConfigDialog(aModel);
SetItemData(myRootItem,aDialog);

UpdateItem(myRootItem);
