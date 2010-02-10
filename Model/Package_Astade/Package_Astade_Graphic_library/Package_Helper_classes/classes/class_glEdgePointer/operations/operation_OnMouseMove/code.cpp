Refresh();

long x ,y;
int sx, sy;
event.GetPosition(&x, &y);
myParent->CalcUnscrolledPosition(x, y, &sx, &sy);

absPosition = mySourceNode.absGetBorderPoint(glVector(sx,sy));
absDrawPosition = absPosition;

Refresh();
event.Skip();