int count = 1;

wxString useName;
useName.Printf("Transition%03d",count);

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
  	configObject.SetPath("..");
  }

	count++;
	useName.Printf("Transition%03d",count);
}
