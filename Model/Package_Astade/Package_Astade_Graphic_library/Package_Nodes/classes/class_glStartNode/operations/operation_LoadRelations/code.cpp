//~~ void LoadRelations(wxConfigBase& configObject) [glStartNode] ~~

int count = 1;

wxString useName;
useName.Printf(wxS("Transition%03d"), count);

while (configObject.Exists(useName))
{
	int UseID;
	configObject.Read(useName,&UseID);
	
	glNode* partnerNode = glNode::getNodeById(UseID);
	
	if (partnerNode)
	{
		glTransition* aTransition = new glTransition(myParent, *this, *partnerNode);
		configObject.SetPath(useName);
		aTransition->Load(configObject);
		configObject.SetPath(wxS(".."));
	}

	count++;
	useName.Printf(wxS("Transition%03d"), count);
}
