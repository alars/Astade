glNode* toNode = getMouseOverNode();

if ((toNode == NULL) || (toNode == this) || (dynamic_cast<glUsecase*>(toNode) == NULL))
    return;

for (std::set<glEdge*>::iterator it = myEdges.begin(); it != myEdges.end(); it++)
{
    if (&((*it)->GetStartNode()) == toNode)
        return;
    if (&((*it)->GetEndNode()) == toNode)
        return;
}

new glAssociation(myParent, *this, *getMouseOverNode());
