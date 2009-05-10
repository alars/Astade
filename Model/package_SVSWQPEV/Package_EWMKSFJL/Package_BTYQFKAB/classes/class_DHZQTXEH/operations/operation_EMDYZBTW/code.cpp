glNode::Save(configObject);
configObject.Write("Label",myLabel);
configObject.Write("ClassName","note");

for (std::set<glEdge*>::iterator it = myEdges.begin(); it != myEdges.end(); it++)
    if (&(*it)->GetStartNode() == this)
    {

    }
