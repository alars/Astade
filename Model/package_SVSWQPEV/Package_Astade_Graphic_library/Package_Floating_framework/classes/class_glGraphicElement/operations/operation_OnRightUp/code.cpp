int usx, usy;
myParent->CalcUnscrolledPosition(event.GetX(), event.GetY(), &usx, &usy);

if (isInElement(glVector(usx,usy)))
{
	myParent->PopupMenu(&myContextMenu);
}
else
	event.Skip();
