glNode* toNode = getMouseOverNode();

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
        if ((toNode == NULL) || (toNode == this) || (dynamic_cast<glUsecase*>(toNode) == NULL))
            return;
        new glAssociation(myParent, *this, *getMouseOverNode());
        break;
    case 1:
        if ((toNode == NULL) || (toNode == this) || (dynamic_cast<glActor*>(toNode) == NULL))
            return;
        new glSpecialize(myParent, *this, *getMouseOverNode());
        break;
}
