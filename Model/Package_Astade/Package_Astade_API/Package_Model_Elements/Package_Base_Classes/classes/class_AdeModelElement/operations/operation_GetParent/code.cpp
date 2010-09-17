//~~ AdeModelElement* GetParent() [AdeModelElement] ~~

wxFileName parentFileName = myFileName;
parentFileName.RemoveLastDir();
parentFileName.SetFullName("ModelNode.ini");
return CreateNewElement(parentFileName);
