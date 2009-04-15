int usx, usy;
myParent->CalcUnscrolledPosition(event.GetX(), event.GetY(), &usx, &usy);

if (isInElement(glVector(usx,usy)))
	LeftDClick();

event.Skip();
