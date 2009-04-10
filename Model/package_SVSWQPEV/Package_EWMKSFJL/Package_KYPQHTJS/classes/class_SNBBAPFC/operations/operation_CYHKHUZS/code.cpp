long x ,y;
int sx, sy;
event.GetPosition(&x, &y);
CalcUnscrolledPosition(x, y, &sx, &sy);
mouseIn = true;
mousePosition = glVector(sx,sy);
glGraphicElement::CheckAllMouseOver();
