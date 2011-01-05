//~~ wxBitmap GetPortIcon(bool isIn, bool isDelegate) [EditIcons] ~~
#include "port_png.h"
#include "delegate_png.h"

wxBitmap aBitmap(imageWidth,imageHeight);
wxMemoryDC dc;
dc.SelectObject(aBitmap);
dc.SetBrush(*wxWHITE_BRUSH);
dc.Clear();

wxMemoryInputStream istream(port_png, sizeof port_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);
dc.DrawBitmap(Scale(myimage),leftBorder,upperBorder,true);

if (isDelegate)
{
	wxMemoryInputStream istream(delegate_png, sizeof delegate_png);
	wxImage overlayimage(istream, wxBITMAP_TYPE_PNG);
	dc.DrawBitmap(Scale(overlayimage),leftBorder,upperBorder,true);
}

return aBitmap;