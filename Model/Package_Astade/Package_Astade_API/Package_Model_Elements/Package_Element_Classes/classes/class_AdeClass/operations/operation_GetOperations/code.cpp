//~~ AdeOperations* GetOperations() [AdeClass] ~~
// return, if we have no operations folder
if (!HasOperations())
	return NULL;

wxFileName aFileName = myFileName;
aFileName.AppendDir(wxS("operations"));

AdeOperations* retVal = dynamic_cast<AdeOperations*>(AdeModelElement::CreateNewElement(aFileName));

return retVal;
