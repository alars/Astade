if (isClicked && event.Dragging())
{
	int usx, usy;
	myParent->CalcUnscrolledPosition(event.GetX(), event.GetY(), &usx, &usy);
	Drag(mousePosition, glVector(usx, usy));
}
event.Skip();