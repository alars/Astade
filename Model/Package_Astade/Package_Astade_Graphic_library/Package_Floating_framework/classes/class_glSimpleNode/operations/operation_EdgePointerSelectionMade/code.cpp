//~~ void EdgePointerSelectionMade() [glSimpleNode] ~~
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
    case 2:
        glVector d = absGetPosition() - getMouseOverNode()-> absGetPosition();
        d /= 3;
        glVector pos1 = absGetPosition() - d;
        d *= 2;
        glVector pos2 = absGetPosition() - d;
        
        glNode* p1 = new glInvisible(myParent,pos1.xCoord(),pos1.yCoord());
        glNode* p2 = new glInvisible(myParent,pos2.xCoord(),pos2.yCoord());
        
        new glSimpleEdge(myParent, *this, *p1);
        new glSimpleEdge(myParent, *p1, *p2);
        new glSimpleEdge(myParent, *p2, *getMouseOverNode());
        break;
}
