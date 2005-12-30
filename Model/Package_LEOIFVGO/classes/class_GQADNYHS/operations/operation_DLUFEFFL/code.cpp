if (startX==stopX)
	return;

dc.DrawLine(startX,	startY, stopX, stopY);

if (startY==stopY)
{
	int x1;

	if (startX < stopX)
		x1 = 15;
	else
		x1 = -15;

	int y1 = 5;
	int y2 = -5;

	switch (arrowHead)
	{
		case ARROWHEADVEE:
			dc.DrawLine(stopX-x1, stopY-y2, stopX, stopY);
			dc.DrawLine(stopX-x1, stopY-y1, stopX, stopY);
		break;

		case ARROWHEADSOLID:
		{
			wxPoint p[3] = {wxPoint(stopX, stopY),wxPoint(stopX-x1, stopY-y2),wxPoint(stopX-x1, stopY-y1)};
			dc.DrawPolygon(3,p);
		}
		break;
	}

	wxCoord w,h;
	dc.GetTextExtent(label, &w, &h);
	w = w/2;

	dc.DrawText(label,startX+((stopX-startX)/2)-w,startY+((stopY-startY)/2)-h);
}
else
{
	double angle = atan2((stopY-startY),(stopX-startX));

	// arrowHead
	double pi = 3.1415926535;
	double ad = 0.35;

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

	wxCoord w,h;
	dc.GetTextExtent(label, &w, &h);
	if (startX<stopX)
		w=-3;

	dc.DrawText(label,startX-w,startY-h+2);
}
