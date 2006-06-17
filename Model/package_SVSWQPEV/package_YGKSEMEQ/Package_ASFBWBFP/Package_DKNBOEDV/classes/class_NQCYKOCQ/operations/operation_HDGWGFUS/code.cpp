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
			myAssociation.insert(myAssociation.begin(),*it);
	count++;
	associationName.Printf("Association%03d",count);
}