dc.DrawLine(startX,	startY, stopX, stopY);

double angle = atan2((stopY-startY),(stopX-startX));

// arrowHead
double ad = 0.45;

double a1 = angle + ad;

int x1 = static_cast<int>(14 * cos(a1));
int y1 = static_cast<int>(14 * sin(a1));

double a2 = angle - ad;

int x2 = static_cast<int>(14 * cos(a2));
int y2 = static_cast<int>(14 * sin(a2));

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

wxCoord w;
wxCoord h;

dc.GetTextExtent(label, &w, &h);
m_LabelWidth = w;
m_LabelHight = h;

if (startX<stopX)
	w=0;

if (startY<stopY)
	h=0;

dc.DrawText(label,startX-w,startY-h);
m_OldLabelRect = wxRect(startX-w,startY-h,m_LabelWidth,m_LabelHight);