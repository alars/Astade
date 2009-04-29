int count = 1;

wxString associationName;
associationName.Printf("Include%03d",count);

while (configObject.Exists(associationName))
{
	int AssociationID;
	configObject.Read(associationName,&AssociationID);
	
	glNode* partnerNode = glNode::getNodeById(AssociationID);
	
	if (partnerNode)
		new glIncludeExtend(myParent, *this, *partnerNode, "\xab" "include" "\xbb");
	
	count++;
	associationName.Printf("Include%03d",count);
}

count = 1;
associationName.Printf("Extention%03d",count);

while (configObject.Exists(associationName))
{
	int AssociationID;
	configObject.Read(associationName,&AssociationID);
	
	glNode* partnerNode = glNode::getNodeById(AssociationID);
	
	if (partnerNode)
		new glIncludeExtend(myParent, *this, *partnerNode, "\xab" "extend" "\xbb");
	
	count++;
	associationName.Printf("Extention%03d",count);
}

count = 1;
associationName.Printf("Superclass%03d",count);

while (configObject.Exists(associationName))
{
	int AssociationID;
	configObject.Read(associationName,&AssociationID);
	
	glNode* partnerNode = glNode::getNodeById(AssociationID);
	
	if (partnerNode)
		new glSpecialize(myParent, *this, *partnerNode);
	
	count++;
	associationName.Printf("Superclass%03d",count);
}

