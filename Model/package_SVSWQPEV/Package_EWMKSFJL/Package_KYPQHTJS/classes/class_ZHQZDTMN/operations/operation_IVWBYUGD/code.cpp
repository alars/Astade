bool mouseInElement;

if (myParent->getMouseIn())
	mouseInElement = isInElement(myParent->getMousePosition());
else
	mouseInElement = false;

if ((mouseOverElement != this) && mouseInElement)
{
	mouseOverElement = this;
	Refresh();
}

if ((mouseOverElement == this) && !mouseInElement)
{
	mouseOverElement = NULL;
	Refresh();
}
