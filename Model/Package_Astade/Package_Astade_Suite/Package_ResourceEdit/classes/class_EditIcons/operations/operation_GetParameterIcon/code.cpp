#include "parameter_png.h"
#include "inparameter_png.h"
#include "outparameter_png.h"
#include "inouparameter_png.h"

wxMemoryInputStream istream(parameter_png, sizeof parameter_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

wxBitmap aBitmap(imageWidth,imageHeight);
wxMemoryDC dc;
dc.SelectObject(aBitmap);
dc.SetBrush(*wxWHITE_BRUSH);

dc.Clear();
dc.DrawBitmap(Scale(myimage),leftBorder,upperBorder,true);

if (isIn && isOut)
{
	wxMemoryInputStream istream(inouparameter_png, sizeof inouparameter_png);
	wxImage overlayimage(istream, wxBITMAP_TYPE_PNG);
	dc.DrawBitmap(Scale(overlayimage),leftBorder,upperBorder,true);
}
else if (isIn)
{
	wxMemoryInputStream istream(inparameter_png, sizeof inparameter_png);
	wxImage overlayimage(istream, wxBITMAP_TYPE_PNG);
	dc.DrawBitmap(Scale(overlayimage),leftBorder,upperBorder,true);
}
else if (isOut)
{
	wxMemoryInputStream istream(outparameter_png, sizeof outparameter_png);
	wxImage overlayimage(istream, wxBITMAP_TYPE_PNG);
	dc.DrawBitmap(Scale(overlayimage),leftBorder,upperBorder,true);
}

return aBitmap;