//~~ AdeModelElement* GetGrandParent() [AdeModelElement] ~~

wxFileName grandparentFileName = myFileName;
grandparentFileName.RemoveLastDir();
grandparentFileName.RemoveLastDir();
grandparentFileName.SetFullName("ModelNode.ini");
return CreateNewElement(grandparentFileName);
