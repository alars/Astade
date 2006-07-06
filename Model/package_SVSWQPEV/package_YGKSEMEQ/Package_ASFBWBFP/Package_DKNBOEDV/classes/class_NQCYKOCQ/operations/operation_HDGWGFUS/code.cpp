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
		{
			GrafArrow* anArrow = new GrafArrow(*this,**it,ARROWHEADNONE,"",wxSOLID,"red");
			m_Parent->DeclareEdge(anArrow);
			myAssociation.insert(myAssociation.begin(),anArrow);
		}
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
		{
			GrafArrow* anArrow = new GrafArrow(*this,**it,ARROWHEADSOLID,"",wxSOLID,"blue");
			m_Parent->DeclareEdge(anArrow);
			mySuperclass.insert(mySuperclass.begin(),anArrow);
		}
	count++;
	associationName.Printf("Superclass%03d",count);
}