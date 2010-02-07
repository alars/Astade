int count = 1;

wxString useName;
useName.Printf("InterfaceUse%03d",count);

while (configObject.Exists(useName))
{
	int UseID;
	configObject.Read(useName,&UseID);
	
	glNode* partnerNode = glNode::getNodeById(UseID);
	
	if (partnerNode)
		new glUseInterface(myParent, *this, *partnerNode);
	
	count++;
	useName.Printf("InterfaceUse%03d",count);
}

count = 1;

wxString provideName;
provideName.Printf("InterfaceProvide%03d",count);

while (configObject.Exists(provideName))
{
	int ProvideID;
	configObject.Read(provideName,&ProvideID);
	
	glNode* partnerNode = glNode::getNodeById(ProvideID);
	
	if (partnerNode)
		new glProvideInterface(myParent, *this, *partnerNode);
	
	count++;
	provideName.Printf("InterfaceProvide%03d",count);
}


