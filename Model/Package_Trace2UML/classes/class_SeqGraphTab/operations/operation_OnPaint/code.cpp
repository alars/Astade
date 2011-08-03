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

#ifdef __WXMSW__
// Get the handle of the wxWindow
HWND hwnd = (HWND)this->GetHandle();

// Now get the native windows DC for this window
HDC hdc = ::GetDC(hwnd);

// Create a double buffer for blitting to
// the screen to prevent screen flicker. Pass
// the double buffer to cairo and blit it
// in the paint routine.
HDC dcbuffer = CreateCompatibleDC(hdc);
wxRect rect = GetClientRect();
HBITMAP hbuffer = CreateCompatibleBitmap(hdc, rect.width, rect.height);
SelectObject(dcbuffer, hbuffer); 

// Create a cairo surface we can draw on directly
cairo_surface_t* cairo_surface = cairo_win32_surface_create(dcbuffer);
cairo_t* cr = cairo_create(cairo_surface);
setColor(cr, white);
cairo_rectangle(cr, 0.0, 0.0, rect.width, winHight);
cairo_fill(cr);
#else
// If it's GTK then use the gdk_cairo_create() method. The GdkDrawable object
// is stored in m_window of the wxPaintDC.
cairo_t* cr = gdk_cairo_create(dc.m_window);
#endif

cairo_translate(cr, 0.5 + dc.LogicalToDeviceX(0), 0.5 + dc.LogicalToDeviceY(0));
DrawOnCr(cr, true);

#ifdef __WXMSW__
// Now blit the object to the screen
BitBlt(hdc, 0, 0, rect.width, rect.height, dcbuffer, 0, 0, SRCCOPY);

// Tear down the cairo object now that we don't need
// it anymore.
cairo_destroy(cr);
cairo_surface_destroy(cairo_surface);

DeleteDC(dcbuffer);
DeleteObject(hbuffer);

// Because we called ::GetDC make sure we release the handle
// back to the system or we'll have a memory leak.
::ReleaseDC(hwnd,hdc);
#else
cairo_destroy(cr);
#endif
