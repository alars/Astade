//~~ AdeModelElement* GetParent() [AdeModelElement] ~~

wxFileName parentFileName = myFileName;
parentFileName.RemoveLastDir();
parentFileName.SetFullName(wxS("ModelNode.ini"));
return CreateNewElement(parentFileName);
