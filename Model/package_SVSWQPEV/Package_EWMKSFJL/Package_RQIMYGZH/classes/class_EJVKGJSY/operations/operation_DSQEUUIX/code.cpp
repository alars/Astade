Refresh();

long x ,y;
int sx, sy;
event.GetPosition(&x, &y);
myParent->CalcUnscrolledPosition(x, y, &sx, &sy);
glGraphicElement::mouseIn = true;
glGraphicElement::mousePosition = glVector(sx,sy);

absPosition = mySourceNode.absGetBorderPoint(mousePosition);
absDrawPosition = absPosition;

Refresh();
event.Skip();