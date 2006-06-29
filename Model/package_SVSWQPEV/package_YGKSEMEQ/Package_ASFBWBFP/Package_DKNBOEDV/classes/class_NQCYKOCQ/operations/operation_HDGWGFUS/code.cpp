GrafNode::Load(configObject);

int count = 1;

wxString associationName;
associationName.Printf("Association%03d",count);

while (configObject.Exists(associationName))
{
	int AssociationID;
	configObject.Read(associationName,&AssociationID);
	for (std::set<GrafNode*>::const_iterator it = m_Parent->GetGrafNodes().begin(); it != m_Parent->GetGrafNodes().end(); it++)
		if ((*it)->GetNodeID()==AssociationID)
			myAssociation.insert(myAssociation.begin(),new GrafArrow(*this,**it,ARROWHEADNONE,"",wxSOLID,"red"));
	count++;
	associationName.Printf("Association%03d",count);
}

count = 1;
associationName.Printf("Superclass%03d",count);

while (configObject.Exists(associationName))
{
	int AssociationID;
	configObject.Read(associationName,&AssociationID);
	for (std::set<GrafNode*>::const_iterator it = m_Parent->GetGrafNodes().begin(); it != m_Parent->GetGrafNodes().end(); it++)
		if ((*it)->GetNodeID()==AssociationID)
			mySuperclass.insert(mySuperclass.begin(),new GrafArrow(*this,**it,ARROWHEADSOLID,"",wxSOLID,"blue"));
	count++;
	associationName.Printf("Superclass%03d",count);
}