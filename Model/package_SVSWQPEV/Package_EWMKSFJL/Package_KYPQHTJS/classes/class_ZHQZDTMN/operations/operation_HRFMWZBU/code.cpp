if (isClicked && event.Dragging())
{
	int usx, usy;
	myParent->CalcUnscrolledPosition(event.GetX(), event.GetY(), &usx, &usy);
	Drag(myParent->mousePosition, glVector(usx, usy));
}
event.Skip();