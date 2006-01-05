if (startX==stopX)
	return;

dc.DrawLine(startX,	startY, stopX, stopY);

if (startY==stopY)
{
	int x1;

	if (startX < stopX)
		x1 = 13;
	else
		x1 = -13;

	int y1 = 4;
	int y2 = -4;

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
	double ad = 0.31;

	double a1 = angle + ad;

	int x1 = 14 * cos(a1);
	int y1 = 14 * sin(a1);

	double a2 = angle - ad;

	int x2 = 14 * cos(a2);
	int y2 = 14 * sin(a2);

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
