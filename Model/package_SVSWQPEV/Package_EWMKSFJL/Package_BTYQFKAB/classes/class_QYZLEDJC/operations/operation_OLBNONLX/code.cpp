if (isClicked)
{
	Stop();
	return;
}

glVector forceSum = myGravityArea->GetBorderForce();

for (std::set<glGravityArea*>::iterator it = glGravityArea::GetObjectList().begin(); it != glGravityArea::GetObjectList().end(); it++)
{
	if (((*it) != myGravityArea) && ((*it) != &myFloatingLabel))
	{
	  forceSum += (*it)->GetForceFromArea(*myGravityArea);
	}
}

AddSpeed(forceSum);

for (std::set<glEdge*>::iterator it = myEdges.begin(); it != myEdges.end(); it++)
	AddSpeed((*it)->NodeForce(*this));

glFloatingItem::Move();
