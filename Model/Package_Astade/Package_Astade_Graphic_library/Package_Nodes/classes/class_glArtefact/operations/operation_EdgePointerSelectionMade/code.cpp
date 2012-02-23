//~~ void EdgePointerSelectionMade() [glArtefact] ~~
glNode* toNode = getMouseOverNode();

if ((toNode == NULL) || (toNode == this))
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
        if (dynamic_cast<glActivity*>(toNode) != NULL)
            new glCreateArtefact(myParent, *this, *toNode);
        break;
    case 1:
        if (dynamic_cast<glActivity*>(toNode) != NULL)
            new glCreateArtefact(myParent, *toNode, *this);
        break;
    case 2:
        if (dynamic_cast<glArtefact*>(toNode) != NULL)
            new glArtefactDependency(myParent, *this, *toNode);
        break;
}
