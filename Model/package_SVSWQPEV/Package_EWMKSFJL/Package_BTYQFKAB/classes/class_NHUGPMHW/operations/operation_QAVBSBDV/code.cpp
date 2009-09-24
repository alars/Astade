int count = 1;

wxString useName;
useName.Printf("Transition%03d",count);

while (configObject.Exists(useName))
{
	int UseID;
	configObject.Read(useName,&UseID);
	
	glNode* partnerNode = glNode::getNodeById(UseID);
	
	if (partnerNode)
		new glTransition(myParent, *this, *partnerNode);
	
	count++;
	useName.Printf("Transition%03d",count);
}
