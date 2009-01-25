long x ,y;
int sx, sy;
event.GetPosition(&x, &y);
CalcUnscrolledPosition(x, y, &sx, &sy);
glGraphicElement::mouseIn = true;
glGraphicElement::mousePosition = glVector(sx,sy);