int usx, usy;
myParent->CalcUnscrolledPosition(event.GetX(), event.GetY(), &usx, &usy);

if (isInElelement(glVector(usx,usy)))
{
	myParent->PopupMenu(&myContextMenu);
}
else
	event.Skip();
