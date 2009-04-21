glVector forceSum = GetBorderForce();

for (std::set<glGravityArea*>::iterator it = glGravityArea::GetObjectList().begin(); it != glGravityArea::GetObjectList().end(); it++)
{
	if (((*it) != this) && (dynamic_cast<glStraightEdge*>(*it) == NULL))
	{
	  forceSum += (*it)->GetForceFromArea(*this);
	}
}

AddSpeed(forceSum);

glVector Anchor = myGraphicElement->absGetAnchorPoint(this);
glVector ancorDist = Anchor-absCalculateNearestToPoint(Anchor);

ancorDist *= 0.7;
AddSpeed(ancorDist);

glFloatingItem::Move();
