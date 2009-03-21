if (isClicked)
{
	Stop();
	return;
}

int w,h;
myParent->GetVirtualSize(&w,&h);

AddSpeed(myGravityArea->GetBorderForce(w,h));
AddSpeed(myGravityArea->GetRelationForce());

for (std::set<glEdge*>::iterator it = myEdges.begin(); it != myEdges.end(); it++)
	AddSpeed((*it)->NodeForce(*this));

glFloatingItem::Move();

bool mouseInElement;

if (myParent->getMouseIn())
	mouseInElement = isInElement(myParent->getMousePosition());
else
	mouseInElement = false;

if ((mouseOverNode != this) && mouseInElement)
{
	mouseOverNode = this;
	Refresh();
}

if ((mouseOverNode == this) && !mouseInElement)
{
	mouseOverNode = NULL;
	Refresh();
}