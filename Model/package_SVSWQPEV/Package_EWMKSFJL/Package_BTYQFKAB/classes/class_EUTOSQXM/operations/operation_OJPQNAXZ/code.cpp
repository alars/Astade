glNode* toNode = getMouseOverNode();

if ((toNode == NULL) || (dynamic_cast<glClass*>(toNode) == NULL))
    return;

if (toNode == this)
{
    glVector dir(-1000,-1000);
    dir = dir.RotateDegree(-90*mySelfEdges.size());
    new glSelfRelation(*myParent, *this, absGetBorderPoint(absGetPosition()+dir));
}
else
{
    new glRelation(myParent, *this, *getMouseOverNode());
}
