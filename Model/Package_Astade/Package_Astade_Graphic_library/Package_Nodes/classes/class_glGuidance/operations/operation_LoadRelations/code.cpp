//~~ void LoadRelations(wxConfigBase& configObject) [glGuidance] ~~

int count = 1;

wxString associationName;
associationName.Printf(wxS("Association%03d"), count);

while (configObject.Exists(associationName))
{
	int AssociationID;
	configObject.Read(associationName, &AssociationID);
	
	glNode* partnerNode = glNode::getNodeById(AssociationID);
	
	if (partnerNode)
		new glAssociation(myParent, *this, *partnerNode);
	
	count++;
	associationName.Printf(wxS("Association%03d"), count);
}

count = 1;
associationName.Printf(wxS("Superclass%03d"), count);

while (configObject.Exists(associationName))
{
	int AssociationID;
	configObject.Read(associationName, &AssociationID);
	
	glNode* partnerNode = glNode::getNodeById(AssociationID);
	
	if (partnerNode)
		new glSpecialize(myParent, *this, *partnerNode);
	
	count++;
	associationName.Printf(wxS("Superclass%03d"), count);
}
