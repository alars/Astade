// return, if we have no operations folder
if(!GetHasOperations())
	return NULL;

wxFileName aFileName = myFileName;
aFileName.AppendDir("operations");

AdeOperations* retVal = dynamic_cast<AdeOperations*>(AdeModelElement::CreateNewElement(aFileName));

return retVal;