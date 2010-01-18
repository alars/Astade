if (isClicked)
{
    Stop();
    return;
}

glVector forceSum = myGravityArea->GetBorderForce();

for (std::set<glGravityArea*>::iterator it = glGravityArea::GetObjectList().begin(); it != glGravityArea::GetObjectList().end(); it++)
{
    if (((*it) != myGravityArea) && (mySelfEdges.find(dynamic_cast<glSelfEdge*>(*it)) == mySelfEdges.end()))
    {
        forceSum += (*it)->GetForceFromArea(*myGravityArea);
    }
}

AddSpeed(forceSum);

for (std::set<glEdge*>::iterator it = myEdges.begin(); it != myEdges.end(); it++)
    AddSpeed((*it)->NodeForce(*this));
    
for (std::set<glSelfEdge*>::iterator it = mySelfEdges.begin(); it != mySelfEdges.end(); it++)
    AddSpeed((*it)->GetAnchorForce());
    
glFloatingItem::Move();
