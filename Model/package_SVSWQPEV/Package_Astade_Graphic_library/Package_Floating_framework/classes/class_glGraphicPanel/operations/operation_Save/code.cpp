configObject.DeleteGroup("Nodes");
glNode::UnifyNodeIds();

int count = 1;
wxString nodeName;
nodeName.Printf("Nodes/Node%03d",count);
glNode* aNode = glNode::getNodeById(count);


while (aNode)
{
	configObject.SetPath(nodeName);

	aNode->Save(configObject);

	count++;
	nodeName.Printf("/Nodes/Node%03d",count);
    aNode = glNode::getNodeById(count);
	configObject.SetPath("../..");
}

