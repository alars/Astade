glVector forceSum = GetBorderForce();

for (std::set<glGravityArea*>::iterator it = glGravityArea::GetObjectList().begin(); it != glGravityArea::GetObjectList().end(); it++)
{
	if (((*it) != this) && ((*it) != ignorArea) && (dynamic_cast<glStraightEdge*>(*it) == NULL))
	{
	  forceSum += (*it)->GetForceFromArea(*this);
	}
}

AddSpeed(forceSum);

glVector Anchor = myGraphicElement->absGetAnchorPoint(this);
glVector ancorDist = absCalculateNearestToPoint(Anchor);
glVector AnchorDir = (Anchor-ancorDist).Dir();
double mod = (Anchor-ancorDist).Mod()-anchorDistance;

AnchorDir *= 0.01;
AnchorDir *= mod;

AddSpeed(AnchorDir);

glFloatingItem::Move();
