GrafNode::Load(configObject);

int count = 1;

wxString associationName;
associationName.Printf("Include%03d",count);

while (configObject.Exists(associationName))
{
	int AssociationID;
	configObject.Read(associationName,&AssociationID);
	for (std::set<GrafNode*>::const_iterator it = m_Parent->GetGrafNodes().begin(); it != m_Parent->GetGrafNodes().end(); it++)
		if ((*it)->GetNodeID()==AssociationID)
			myInclude.insert(myInclude.begin(),*it);
	count++;
	associationName.Printf("Include%03d",count);
}

count = 1;
associationName.Printf("Extention%03d",count);

while (configObject.Exists(associationName))
{
	int AssociationID;
	configObject.Read(associationName,&AssociationID);
	for (std::set<GrafNode*>::const_iterator it = m_Parent->GetGrafNodes().begin(); it != m_Parent->GetGrafNodes().end(); it++)
		if ((*it)->GetNodeID()==AssociationID)
			myExtent.insert(myExtent.begin(),*it);
	count++;
	associationName.Printf("Extention%03d",count);
}

count = 1;
associationName.Printf("Superclass%03d",count);

while (configObject.Exists(associationName))
{
	int AssociationID;
	configObject.Read(associationName,&AssociationID);
	for (std::set<GrafNode*>::const_iterator it = m_Parent->GetGrafNodes().begin(); it != m_Parent->GetGrafNodes().end(); it++)
		if ((*it)->GetNodeID()==AssociationID)
			mySuperclass.insert(mySuperclass.begin(),*it);
	count++;
	associationName.Printf("Superclass%03d",count);
}