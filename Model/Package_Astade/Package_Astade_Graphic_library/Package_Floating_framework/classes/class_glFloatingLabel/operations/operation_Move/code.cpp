glVector forceSum = GetBorderForce();

for (std::set<glGravityArea*>::iterator it = glGravityArea::GetObjectList().begin(); it != glGravityArea::GetObjectList().end(); it++)
{
	if (((*it) != this) && (dynamic_cast<glStraightEdge*>(*it) == NULL) && (dynamic_cast<glSelfEdge*>(*it) == NULL))
	{
	  forceSum += (*it)->GetForceFromArea(*this);
	}
}

AddSpeed(forceSum);

glVector anchorForce = GetAnchorForce();
anchorForce *= -1;
AddSpeed(anchorForce);

glFloatingItem::Move();
