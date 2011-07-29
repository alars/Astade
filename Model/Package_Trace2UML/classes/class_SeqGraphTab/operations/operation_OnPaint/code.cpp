//~~ void OnPaint(wxPaintEvent& event) [SeqGraphTab] ~~
SetVirtualSize(dataBase->GetGraphWidth(), dataBase->GetGraphHeight());

wxPaintDC dc(this);
DoPrepareDC(dc);

int xScroll;
CalcUnscrolledPosition(0,0,&xScroll, &m_scroll);

int winWidth, winHight;
GetSize(&winWidth, &winHight);

m_scrollEnd = m_scroll + winHight + 50;
m_scroll -= 50;

DrawOnDC(dc, true);

// If it's GTK then use the gdk_cairo_create() method. The GdkDrawable object
// is stored in m_window of the wxPaintDC.
cairo_t* cr = gdk_cairo_create(dc.m_window);


double xc = 128.0;
double yc = 128.0;
double radius = 100.0;
double angle1 = 45.0  * (M_PI/180.0);  /* angles are specified */
double angle2 = 180.0 * (M_PI/180.0);  /* in radians           */

cairo_set_line_width (cr, 10.0);
cairo_arc (cr, xc, yc, radius, angle1, angle2);
cairo_stroke (cr);

/* draw helping lines */
cairo_set_source_rgba (cr, 1, 0.2, 0.2, 0.6);
cairo_set_line_width (cr, 6.0);

cairo_arc (cr, xc, yc, 10.0, 0, 2*M_PI);
cairo_fill (cr);

cairo_arc (cr, xc, yc, radius, angle1, angle1);
cairo_line_to (cr, xc, yc);
cairo_arc (cr, xc, yc, radius, angle2, angle2);
cairo_line_to (cr, xc, yc);
cairo_stroke (cr);




cairo_destroy(cr);

