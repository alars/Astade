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