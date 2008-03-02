#include "class_png.h"
#include "c_png.h"

wxMemoryInputStream istream(class_png, sizeof class_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

wxMemoryInputStream istream2(c_png, sizeof c_png);
wxImage cImage(istream2, wxBITMAP_TYPE_PNG);

wxBitmap aBitmap(imageWidth,imageHeight);
wxMemoryDC dc;
dc.SelectObject(aBitmap);
dc.SetBrush(*wxWHITE_BRUSH);

dc.Clear();
dc.DrawBitmap(Scale(myimage),leftBorder,upperBorder,true);

if (isCCoded)
	dc.DrawBitmap(Scale(cImage),leftBorder,upperBorder,true);

return aBitmap;