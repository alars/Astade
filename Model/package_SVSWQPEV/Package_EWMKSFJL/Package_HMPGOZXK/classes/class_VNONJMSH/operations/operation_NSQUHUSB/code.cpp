if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),2,wxSOLID));
else
  dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLUE"),1,wxSOLID));

glVector m = absCalculateCenterPoint();

double angle = acos(lastStartPoint.Dir().ScalarProduct(lastEndPoint.Dir()));

angle /= 10;

if (width<0)
	angle = -angle;

glVector it(lastStartPoint);
glVector it2(it);

for (int i=0; i<10; i++)
{
	it2 = it;
	if (i != 9)
		it = it.RotateRadians(angle);
	else
		it = lastEndPoint;
	glVector start = m+it;
	glVector end = m+it2;
	dc.DrawLine(start.xCoord(),start.yCoord(),end.xCoord(),end.yCoord());
}

