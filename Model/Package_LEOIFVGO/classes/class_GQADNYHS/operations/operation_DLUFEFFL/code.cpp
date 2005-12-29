if (startX==stopX)
	return;

dc.DrawLine(startX,	startY, stopX, stopY);

double angle = atan((stopY-startY)/(stopX-startX));

// arrowHead
double pi = 3.1415926535;
double ad = 0.35;

if (stopX<startX)
	angle += pi;

double a1 = angle + ad;

int x1 = 16 * cos(a1);
int y1 = 16 * sin(a1);

double a2 = angle - ad;

int x2 = 16 * cos(a2);
int y2 = 16 * sin(a2);

switch (arrowHead)
{
	case ARROWHEADVEE:
		dc.DrawLine(stopX-x2, stopY-y2, stopX, stopY);
		dc.DrawLine(stopX-x1, stopY-y1, stopX, stopY);
	break;

	case ARROWHEADSOLID:
	{
		wxPoint p[3] = {wxPoint(stopX, stopY),wxPoint(stopX-x2, stopY-y2),wxPoint(stopX-x1, stopY-y1)};
		dc.DrawPolygon(3,p);
	}
	break;
}

// calculating textposition

while (angle >= (pi/2))
	angle -= (pi/2);

double s = sin(angle);
double c = cos(angle);

wxCoord w,h;
dc.GetTextExtent(label, &w, &h);
w = w/2;

dc.DrawRotatedText(label,startX+((stopX-startX)/2)-(w*c)+(h*s),startY+((stopY-startY)/2)-(h*c)-(w*s),angle);
