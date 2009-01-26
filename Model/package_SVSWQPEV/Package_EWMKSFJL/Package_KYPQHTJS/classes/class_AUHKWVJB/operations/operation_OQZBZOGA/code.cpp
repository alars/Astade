glFloatingItem::Move();

bool mouseInElement;

if (myParent->mouseIn)
	mouseInElement = isInElement(myParent->mousePosition);
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