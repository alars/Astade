SetImageList(&myIcons);
myRootItem = AddRoot("model",5);

AdeModelElement* aModel=new AdeModel;
SetItemData(myRootItem,aModel);

UpdateItem(myRootItem);
