//~~ void EdgePointerSelectionMade() [glComponent] ~~

glNode* toNode = getMouseOverNode();

if ((toNode == NULL) || (toNode == this) || 
    ((dynamic_cast<glInterface*>(toNode) == NULL) && (dynamic_cast<glComponent*>(toNode) == NULL)))
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
        if (dynamic_cast<glComponent*>(toNode) == NULL)
            new glProvideInterface(myParent, *this, *toNode);
        break;
    case 1:
        if (dynamic_cast<glComponent*>(toNode) != NULL)
        {
            new glIncludeExtend(myParent, *this, *toNode, wxS("\xab" "use" "\xbb"));
        }
        else
        {
            new glUseInterface(myParent, *this, *toNode);
        }
        break;
}
