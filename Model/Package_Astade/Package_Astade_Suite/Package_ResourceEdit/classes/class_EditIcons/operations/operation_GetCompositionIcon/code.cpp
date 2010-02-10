#include "composition_png.h"

wxMemoryInputStream istream(composition_png, sizeof composition_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

wxBitmap aBitmap(imageWidth,imageHeight);
wxMemoryDC dc;
dc.SelectObject(aBitmap);
dc.SetBrush(*wxWHITE_BRUSH);

dc.Clear();
dc.DrawBitmap(Scale(myimage),leftBorder,upperBorder,true);

return aBitmap;