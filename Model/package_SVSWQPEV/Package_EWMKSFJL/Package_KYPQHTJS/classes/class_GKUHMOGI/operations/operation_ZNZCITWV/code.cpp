glVector forceSum;

for (std::set<glGravityArea*>::iterator it = glGravityArea::GetObjectList().begin(); it != glGravityArea::GetObjectList().end(); it++)
{
	if (((*it) != this) && ((*it) != ignorArea) && (dynamic_cast<glStraightEdge*>(*it) == NULL))
	{
	  forceSum += (*it)->GetForceFromArea(*this);
	}
}

AddSpeed(forceSum);

glVector ancorDist = absCalculateNearestToPoint(myGraphicElement->absGetAnchorPoint(this)) - absPosition;
ancorDist *= 0.1;
AddSpeed(ancorDist);

glFloatingItem::Move();
