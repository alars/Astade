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
		{
			GrafArrow* anArrow = new GrafArrow(*this,**it,ARROWHEADVEE,"<<include>>",wxSHORT_DASH,"blue");
			m_Parent->DeclareEdge(anArrow);
			myInclude.insert(myInclude.begin(),anArrow);
		}
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
		{
			GrafArrow* anArrow = new GrafArrow(*this,**it,ARROWHEADVEE,"<<extend>>",wxSHORT_DASH,"blue");
			m_Parent->DeclareEdge(anArrow);
			myExtend.insert(myExtend.begin(),anArrow);
		}
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
		{
			GrafArrow* anArrow = new GrafArrow(*this,**it,ARROWHEADSOLID,"",wxSOLID,"blue");
			m_Parent->DeclareEdge(anArrow);
			mySuperclass.insert(mySuperclass.begin(),anArrow);
		}
	count++;
	associationName.Printf("Superclass%03d",count);
}