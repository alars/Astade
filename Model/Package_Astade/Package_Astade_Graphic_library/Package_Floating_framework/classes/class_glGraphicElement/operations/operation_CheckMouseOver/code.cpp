bool mouseInElement;

if (myParent->getMouseIn())
	mouseInElement = isInElement(myParent->getMousePosition());
else
	mouseInElement = false;

if ((mouseOverElement != this) && mouseInElement)
{
    if (mouseOverElement != NULL)
        mouseOverElement->Refresh();
	mouseOverElement = this;
	Refresh();
}

if ((mouseOverElement == this) && !mouseInElement)
{
	mouseOverElement = NULL;
	Refresh();
}
