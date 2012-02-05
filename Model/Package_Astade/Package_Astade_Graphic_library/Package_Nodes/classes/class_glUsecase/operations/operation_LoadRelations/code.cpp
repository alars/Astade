//~~ void LoadRelations(wxConfigBase& configObject) [glUsecase] ~~

int count = 1;

wxString associationName;
associationName.Printf(wxS("Include%03d"), count);

while (configObject.Exists(associationName))
{
	int AssociationID;
	configObject.Read(associationName, &AssociationID);
	
	glNode* partnerNode = glNode::getNodeById(AssociationID);
	
	if (partnerNode)
		new glIncludeExtend(myParent, *this, *partnerNode, wxS("\xab" "include" "\xbb"));
	
	count++;
	associationName.Printf(wxS("Include%03d"), count);
}

count = 1;
associationName.Printf(wxS("Extention%03d"), count);

while (configObject.Exists(associationName))
{
	int AssociationID;
	configObject.Read(associationName,&AssociationID);
	
	glNode* partnerNode = glNode::getNodeById(AssociationID);
	
	if (partnerNode)
		new glIncludeExtend(myParent, *this, *partnerNode, wxS("\xab" "extend" "\xbb"));
	
	count++;
	associationName.Printf(wxS("Extention%03d"), count);
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
