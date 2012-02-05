//~~ void EdgePointerSelectionMade() [glUsecase] ~~

glNode* toNode = getMouseOverNode();

if (toNode == NULL || toNode == this || dynamic_cast<glUsecase*>(toNode) == NULL)
    return;

for (std::set<glEdge*>::iterator it = myEdges.begin(); it != myEdges.end(); ++it)
{
    if (&((*it)->GetStartNode()) == toNode)
        return;
    if (&((*it)->GetEndNode()) == toNode)
        return;
}

switch (edgeToCreate)
{
    case 0:
        new glIncludeExtend(myParent, *this, *getMouseOverNode(), wxS("\xab" "include" "\xbb"));
        break;
    case 1:
        new glIncludeExtend(myParent, *this, *getMouseOverNode(), wxS("\xab" "extend" "\xbb"));
        break;
    case 2:
        new glSpecialize(myParent, *this, *getMouseOverNode());
        break;
}
