int usx, usy;
myParent->CalcUnscrolledPosition(event.GetX(), event.GetY(), &usx, &usy);

if (isInElelement(glVector(usx,usy)))
{
}
else
	event.Skip();
