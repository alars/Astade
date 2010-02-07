glNode* toNode = getMouseOverNode();

if ((toNode == NULL) || (toNode == this) || (dynamic_cast<glInterface*>(toNode) == NULL))
    return;

for (std::set<glEdge*>::iterator it = myEdges.begin(); it != myEdges.end(); it++)
{
    if (&((*it)->GetStartNode()) == toNode)
        return;
    if (&((*it)->GetEndNode()) == toNode)
        return;
}

switch (edgeToCreate)
{
    case 0:
        new glProvideInterface(myParent, *this, *getMouseOverNode());
        break;
    case 1:
        new glUseInterface(myParent, *this, *getMouseOverNode());
        break;
}
