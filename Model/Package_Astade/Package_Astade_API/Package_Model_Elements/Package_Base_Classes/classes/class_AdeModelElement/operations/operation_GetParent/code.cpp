//~~ AdeModelElement* GetParent() [AdeModelElement] ~~
wxFileName parentFileName = myFileName;
parentFileName.RemoveLastDir();
return CreateNewElement(parentFileName);