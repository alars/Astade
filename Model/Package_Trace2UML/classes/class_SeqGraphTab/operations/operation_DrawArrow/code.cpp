//~~ void DrawArrow(cairo_t* cr, int startX, int startY, int stopX, int stopY, arrowHead_t arrowHead, const wxString& label, color_t color) [SeqGraphTab] ~~
setColor(cr, color);
cairo_set_line_width (cr, 0.7);
cairo_move_to(cr, startX, startY);
cairo_line_to (cr, stopX, stopY);
cairo_stroke (cr);

cairo_set_dash(cr,0,0,0); // do dashes in arrowhead

double angle = atan2((stopY-startY),(stopX-startX));

// arrowHead
double ad = 0.33;
double headSize = 10;

double a1 = angle + ad;

double x1 = headSize * cos(a1);
double y1 = headSize * sin(a1);

double a2 = angle - ad;

double x2 = headSize * cos(a2);
double y2 = headSize * sin(a2);

switch (arrowHead)
{
    case ARROWHEADVEE:
        cairo_move_to(cr, stopX-x2, stopY-y2);
        cairo_line_to (cr, stopX, stopY);
        cairo_line_to (cr, stopX-x1, stopY-y1);
        cairo_set_line_join (cr, CAIRO_LINE_JOIN_ROUND);
        cairo_stroke (cr);
    break;

    case ARROWHEADSOLID:
    {
        cairo_move_to(cr, stopX-x2, stopY-y2);
        cairo_line_to (cr, stopX, stopY);
        cairo_line_to (cr, stopX-x1, stopY-y1);
        cairo_close_path(cr);
        cairo_fill_preserve(cr);
        cairo_set_line_join (cr, CAIRO_LINE_JOIN_ROUND);
        cairo_stroke (cr);
    }
    break;
    
    case ARROWHEADNONE:
    break;
}

setColor(cr, black);

if (startX > stopX)
{
    cairo_text_extents_t theExtents;
    cairo_text_extents(cr, label.c_str(), &theExtents);
    double startPos = startX-theExtents.width-2;
    if (startPos < 2)
        startPos = stopX+2;
    cairo_move_to(cr, startPos, startY-2);
    cairo_show_text(cr, label.c_str());
}
else
{
    cairo_move_to(cr, startX+2, startY-2);
    cairo_show_text(cr, label.c_str());
}