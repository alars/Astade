glFloatingItem::Move();

bool mouseInElement;

if (glGraphicElement::mouseIn)
	mouseInElement = isInElement(glGraphicElement::mousePosition);
else
	mouseInElement = false;

if (mouseOver != mouseInElement)
	Refresh();

mouseOver = mouseInElement;