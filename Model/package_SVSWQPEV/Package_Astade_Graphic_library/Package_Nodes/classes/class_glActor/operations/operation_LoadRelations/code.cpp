int count = 1;

wxString associationName;
associationName.Printf("Association%03d",count);

while (configObject.Exists(associationName))
{
	int AssociationID;
	configObject.Read(associationName,&AssociationID);
	
	glNode* partnerNode = glNode::getNodeById(AssociationID);
	
	if (partnerNode)
		new glAssociation(myParent, *this, *partnerNode);
	
	count++;
	associationName.Printf("Association%03d",count);
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

