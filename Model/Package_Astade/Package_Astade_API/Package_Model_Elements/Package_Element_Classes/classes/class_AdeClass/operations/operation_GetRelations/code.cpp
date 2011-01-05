//~~ AdeRelations* GetRelations() [AdeClass] ~~
// return, if we have no operations folder
if (!HasRelations())
	return NULL;

wxFileName aFileName = myFileName;
aFileName.AppendDir(wxS("relations"));

AdeRelations* retVal = dynamic_cast<AdeRelations*>(AdeModelElement::CreateNewElement(aFileName));

return retVal;
