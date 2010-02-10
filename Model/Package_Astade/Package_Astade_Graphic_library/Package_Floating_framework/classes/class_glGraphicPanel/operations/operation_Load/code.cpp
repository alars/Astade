glGraphicElement::DestroyAll();

int count = 1;
wxString nodeName;
nodeName.Printf("Nodes/Node%03d",count);

while (configObject.Exists(nodeName))
{
	configObject.SetPath(nodeName);

	wxString nodeClassName;
	configObject.Read("ClassName",&nodeClassName);
	
	if (nodeClassName == "GrafUseCase")
	    nodeClassName = "usecase";

	if (nodeClassName == "GrafActor")
	    nodeClassName = "actor";

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

count = 1;
nodeName.Printf("Nodes/Node%03d",count);

while (configObject.Exists(nodeName))
{
	configObject.SetPath(nodeName);

	int id;
	configObject.Read("ID",&id);

	glNode* aNode = glNode::getNodeById(id);

	if (aNode)
		aNode->LoadRelations(configObject);

	count++;
	nodeName.Printf("/Nodes/Node%03d",count);
	configObject.SetPath("../..");
}

Refresh();
