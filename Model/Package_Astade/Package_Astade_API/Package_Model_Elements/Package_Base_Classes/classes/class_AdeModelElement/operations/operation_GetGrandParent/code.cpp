//~~ AdeModelElement* GetGrandParent() [AdeModelElement] ~~

wxFileName grandparentFileName = myFileName;
grandparentFileName.RemoveLastDir();
grandparentFileName.RemoveLastDir();
grandparentFileName.SetFullName(wxS("ModelNode.ini"));
return CreateNewElement(grandparentFileName);
