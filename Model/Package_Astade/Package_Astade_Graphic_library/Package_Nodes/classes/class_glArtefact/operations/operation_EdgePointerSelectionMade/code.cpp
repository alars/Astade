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
        new glCreateArtefact(myParent, *this, *getMouseOverNode());
        break;
    case 1:
        new glCreateArtefact(myParent, *getMouseOverNode(), *this);
        break;
}
