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

// If it's GTK then use the gdk_cairo_create() method. The GdkDrawable object
// is stored in m_window of the wxPaintDC.
cairo_t* cr = gdk_cairo_create(dc.m_window);

cairo_translate(cr, 0.5 + dc.LogicalToDeviceX(0), 0.5 + dc.LogicalToDeviceY(0));

DrawOnDC(cr, dc, true);

cairo_destroy(cr);

