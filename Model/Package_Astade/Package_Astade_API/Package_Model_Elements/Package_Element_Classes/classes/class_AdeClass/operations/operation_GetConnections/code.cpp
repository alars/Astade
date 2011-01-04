//~~ AdeConnections* GetConnections() [AdeClass] ~~
// return, if we have no connections folder
if (!HasConnections())
	return NULL;

wxFileName aFileName = myFileName;
aFileName.AppendDir(wxS("connections"));

AdeConnections* retVal = dynamic_cast<AdeConnections*>(AdeModelElement::CreateNewElement(aFileName));

return retVal;
