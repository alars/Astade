glNode* toNode = getMouseOverNode();

if ((toNode == NULL) || ((dynamic_cast<glState*>(toNode) == NULL) && (dynamic_cast<glEndNode*>(toNode) == NULL)))
    return;

if (getMouseOverNode())
{
    if (toNode == this)
    {
        glVector dir(-1000,-1000);
        dir = dir.RotateDegree(-90*mySelfEdges.size());
    	new glSelfTransition(*myParent, *this, absGetBorderPoint(absGetPosition()+dir));
    }
    else
    	new glTransition(myParent, *this, *toNode);
}
