if (isClicked)
{
	Stop();
	return;
}

int w,h;
myParent->GetVirtualSize(&w,&h);

AddSpeed(myGravityArea->GetBorderForce(w,h));
AddSpeed(myGravityArea->GetForceFromAll());

for (std::set<glEdge*>::iterator it = myEdges.begin(); it != myEdges.end(); it++)
	AddSpeed((*it)->NodeForce(*this));

glFloatingItem::Move();
