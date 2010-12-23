//~~ wxBitmap GetPortIcon(bool isIn, bool isDelegate) [EditIcons] ~~
#include "InPort_png.h"
#include "OutPort_png.h"
#include "delegate_png.h"

wxBitmap aBitmap(imageWidth,imageHeight);
wxMemoryDC dc;
dc.SelectObject(aBitmap);
dc.SetBrush(*wxWHITE_BRUSH);
dc.Clear();

if (isIn)
{
    wxMemoryInputStream istream(InPort_png, sizeof InPort_png);
    wxImage myimage(istream, wxBITMAP_TYPE_PNG);
	dc.DrawBitmap(Scale(myimage),leftBorder,upperBorder,true);
}
else
{
    wxMemoryInputStream istream(OutPort_png, sizeof OutPort_png);
    wxImage myimage(istream, wxBITMAP_TYPE_PNG);
	dc.DrawBitmap(Scale(myimage),leftBorder,upperBorder,true);
}

if (isDelegate)
{
	wxMemoryInputStream istream(delegate_png, sizeof delegate_png);
	wxImage overlayimage(istream, wxBITMAP_TYPE_PNG);
	dc.DrawBitmap(Scale(overlayimage),leftBorder,upperBorder,true);
}

return aBitmap;