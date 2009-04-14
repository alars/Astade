if (mouseOverElement == this)
	mouseOverElement = NULL;

objectList.remove(this);
myParent->RemoveEventHandler(this);
