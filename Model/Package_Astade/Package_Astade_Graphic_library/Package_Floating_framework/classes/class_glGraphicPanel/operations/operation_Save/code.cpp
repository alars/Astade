//~~ void Save(wxConfigBase& configObject) [glGraphicPanel] ~~

configObject.DeleteGroup(wxS("Nodes"));
glNode::UnifyNodeIds();

int count = 1;
wxString nodeName;
nodeName.Printf(wxS("Nodes/Node%03d"), count);
glNode* aNode = glNode::getNodeById(count);


while (aNode)
{
	configObject.SetPath(nodeName);

	aNode->Save(configObject);

	count++;
	nodeName.Printf(wxS("/Nodes/Node%03d"), count);
    aNode = glNode::getNodeById(count);
	configObject.SetPath(wxS("../.."));
}

