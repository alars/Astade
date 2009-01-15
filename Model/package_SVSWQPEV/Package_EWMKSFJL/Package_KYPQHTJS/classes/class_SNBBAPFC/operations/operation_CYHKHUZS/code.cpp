long x ,y;
int sx, sy;
event.GetPosition(&x, &y);
CalcScrolledPosition(x, y, &sx, &sy);
glGraphicElement::mouseIn = true;
glGraphicElement::mousePosition = glVector(sx,sy);