//~~ void Load(wxConfigBase& configObject) [glGraphicPanel] ~~

glGraphicElement::DestroyAll();

int count = 1;
wxString nodeName;
nodeName.Printf(wxS("Nodes/Node%03d"), count);

while (configObject.Exists(nodeName))
{
	configObject.SetPath(nodeName);

	wxString nodeClassName;
	configObject.Read(wxS("ClassName"), &nodeClassName);
	
	if (nodeClassName == wxS("GrafUseCase"))
	    nodeClassName = wxS("usecase");

	if (nodeClassName == wxS("GrafActor"))
	    nodeClassName = wxS("actor");

	int x, y;
	configObject.Read(wxS("xPos"), &x);
	configObject.Read(wxS("yPos"), &y);

	glNode* aNode = glCreator::Create(this,nodeClassName, x, y);

	if (aNode)
		aNode->Load(configObject);

	count++;
	nodeName.Printf(wxS("/Nodes/Node%03d"), count);
	configObject.SetPath(wxS("../.."));
}

count = 1;
nodeName.Printf(wxS("Nodes/Node%03d"), count);

while (configObject.Exists(nodeName))
{
	configObject.SetPath(nodeName);

	int id;
	configObject.Read(wxS("ID"), &id);

	glNode* aNode = glNode::getNodeById(id);

	if (aNode)
		aNode->LoadRelations(configObject);

	count++;
	nodeName.Printf(wxS("/Nodes/Node%03d"), count);
	configObject.SetPath(wxS("../.."));
}

Refresh();
