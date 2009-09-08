if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),2,wxSOLID));
else
    dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLUE"),1,wxSOLID));

glVector m = absCalculateCenterPoint();

glVector diff = lastStartPoint - lastEndPoint;

double angle = acos(lastStartPoint.Dir().ScalarProduct(lastEndPoint.Dir()));
//angle = asin(diff.Mod()/radius());

angle /= 10;

glVector it(lastStartPoint);
glVector it2(it);

for (int i=0; i<10; i++)
{
	it2 = it;
	it = it.RotateRadians(angle);
	glVector start = m+it;
	glVector end = m+it2;
	dc.DrawLine(start.xCoord(),start.yCoord(),end.xCoord(),end.yCoord());
}

