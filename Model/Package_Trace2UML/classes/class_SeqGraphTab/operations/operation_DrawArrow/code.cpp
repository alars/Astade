//~~ void DrawArrow(cairo_t* cr, wxDC& dc, int startX, int startY, int stopX, int stopY, int arrowHead, const wxString& label) [SeqGraphTab] ~~
if (startX==stopX)
	return;

cairo_set_line_width (cr, 1.0);
cairo_move_to(cr, startX, startY);
cairo_line_to (cr, stopX, stopY);
cairo_stroke (cr);

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
            cairo_move_to(cr, stopX-x1, stopY-y2);
            cairo_line_to (cr, stopX, stopY);
            cairo_line_to (cr, stopX-x1, stopY-y1);
            cairo_stroke (cr);
		break;

		case ARROWHEADSOLID:
		{
            cairo_move_to(cr, stopX-x1, stopY-y2);
            cairo_line_to (cr, stopX, stopY);
            cairo_line_to (cr, stopX-x1, stopY-y1);
			cairo_close_path(cr);
            cairo_fill(cr);
		}
		break;
	}

	wxCoord w,h;
	dc.GetTextExtent(label, &w, &h);
	if (startX<stopX)
		w=-3;

	dc.DrawText(label,startX-w,startY-h);
}
else
{
	double angle = atan2((stopY-startY),(stopX-startX));

	// arrowHead
	double ad = 0.31;

	double a1 = angle + ad;

	int x1 = static_cast<int>(14 * cos(a1));
	int y1 = static_cast<int>(14 * sin(a1));

	double a2 = angle - ad;

	int x2 = static_cast<int>(14 * cos(a2));
	int y2 = static_cast<int>(14 * sin(a2));

	switch (arrowHead)
	{
		case ARROWHEADVEE:
            cairo_move_to(cr, stopX-x2, stopY-y2);
            cairo_line_to (cr, stopX, stopY);
            cairo_line_to (cr, stopX-x1, stopY-y1);
            cairo_stroke (cr);
		break;

		case ARROWHEADSOLID:
		{
            cairo_move_to(cr, stopX-x2, stopY-y2);
            cairo_line_to (cr, stopX, stopY);
            cairo_line_to (cr, stopX-x1, stopY-y1);
			cairo_close_path(cr);
            cairo_fill(cr);
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
