int count = 1;

wxString relationName;
relationName.Printf("Relation%03d",count);

while (configObject.Exists(relationName))
{
	int relationID;
	configObject.Read(relationName,&relationID);
	
	glNode* partnerNode = glNode::getNodeById(relationID);
	
	if (partnerNode)
		new scRelation(myParent, *this, *partnerNode);
	
	count++;
	relationName.Printf("Relation%03d",count);
}
