if (isClicked)
{
	Stop();
	return;
}

AddSpeed(myGravityArea->GetForceFromAll());

for (std::set<glEdge*>::iterator it = myEdges.begin(); it != myEdges.end(); it++)
	AddSpeed((*it)->NodeForce(*this));

glFloatingItem::Move();
