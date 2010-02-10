glNode* toNode = getMouseOverNode();

if ((toNode == NULL) || (toNode == this))
    return;

switch (edgeToCreate)
{
    case 0:
        new glSimpleEdge(myParent, *this, *getMouseOverNode());
        break;
    case 1:
        new glRoundEdge(myParent, *this, *getMouseOverNode());
        break;
}
