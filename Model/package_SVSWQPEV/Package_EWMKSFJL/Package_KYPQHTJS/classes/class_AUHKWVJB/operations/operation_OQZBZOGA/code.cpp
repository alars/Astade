glFloatingItem::Move();

bool mouseInElement;

if (glGraphicElement::mouseIn)
	mouseInElement = isInElement(glGraphicElement::mousePosition);
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