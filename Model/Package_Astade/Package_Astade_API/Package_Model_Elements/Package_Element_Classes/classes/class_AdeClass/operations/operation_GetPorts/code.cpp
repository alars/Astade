//~~ AdePorts* GetPorts() [AdeClass] ~~
// return, if we have no operations folder
if (!HasPorts())
	return NULL;

wxFileName aFileName = myFileName;
aFileName.AppendDir(wxS("ports"));

AdePorts* retVal = dynamic_cast<AdePorts*>(AdeModelElement::CreateNewElement(aFileName));

return retVal;
