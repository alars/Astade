int w,h;
myParent->GetVirtualSize(&w,&h);

AddSpeed(myGravityArea.GetBorderForce(w,h));
AddSpeed(myGravityArea.GetRelationForce());

glFloatingItem::Move();

bool mouseInElement;

if (glGraphicElement::mouseIn)
	mouseInElement = isInElement(glGraphicElement::mousePosition);
else
	mouseInElement = false;

if (mouseOver != mouseInElement)
	Refresh();

mouseOver = mouseInElement;