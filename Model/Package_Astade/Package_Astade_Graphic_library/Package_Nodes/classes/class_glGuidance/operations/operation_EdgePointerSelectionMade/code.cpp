//~~ void EdgePointerSelectionMade() [glGuidance] ~~
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
        if (dynamic_cast<glActivity*>(toNode) == NULL)
            return;
        new glAttach(myParent, *this, *getMouseOverNode());
        break;
    case 1:
        if (dynamic_cast<glGuidance*>(toNode) == NULL)
            return;
        new glSpecialize(myParent, *this, *getMouseOverNode());
        break;
}
