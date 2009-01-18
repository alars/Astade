int usx, usy;
myParent->CalcUnscrolledPosition(event.GetX(), event.GetY(), &usx, &usy);

if (isInElement(glVector(usx,usy)))
	isClicked = true;
else
	isClicked = false;

event.Skip();