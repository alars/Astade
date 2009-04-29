glGraphicElement::DestroyAll();

int count = 1;
wxString nodeName;
nodeName.Printf("Nodes/Node%03d",count);

while (configObject.Exists(nodeName))
{
	configObject.SetPath(nodeName);

	wxString nodeClassName;
	configObject.Read("ClassName",&nodeClassName);

	int x,y;
	configObject.Read("xPos",&x);
	configObject.Read("yPos",&y);

	glNode* aNode = glCreator::Create(this,nodeClassName,x,y);

	if (aNode)
		aNode->Load(configObject);

	count++;
	nodeName.Printf("/Nodes/Node%03d",count);
	configObject.SetPath("../..");
}

/*

for (std::set<GrafNode*>::iterator it = myGrafNodes.begin(); it != myGrafNodes.end(); it++)
{
	count = (*it)->GetNodeID();
	nodeName.Printf("/Nodes/Node%03d",count);

	if (configObject.Exists(nodeName))
	{
		configObject.SetPath(nodeName);
		(*it)->LoadRelations(configObject);
	}
}
*/
