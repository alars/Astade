objectList.insert(this);
myParent->RemoveEventHandler(myParent);
myParent->PushEventHandler(this);
myParent->PushEventHandler(myParent);