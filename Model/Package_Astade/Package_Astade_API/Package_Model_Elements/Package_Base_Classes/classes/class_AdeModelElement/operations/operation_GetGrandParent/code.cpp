//~~ AdeModelElement* GetGrandParent() [AdeModelElement] ~~
wxFileName grandparentFileName = myFileName;
grandparentFileName.RemoveLastDir();
grandparentFileName.RemoveLastDir();
return CreateNewElement(grandparentFileName);