#include "relation_png.h"
#include "h_png.h"

wxMemoryInputStream relationstream(relation_png, sizeof relation_png);
wxImage relationimage(relationstream, wxBITMAP_TYPE_PNG);

wxMemoryInputStream hstream(h_png, sizeof h_png);
wxImage himage(hstream, wxBITMAP_TYPE_PNG);

wxBitmap aBitmap(imageWidth,imageHeight);
wxMemoryDC dc;
dc.SelectObject(aBitmap);
dc.SetBrush(*wxWHITE_BRUSH);

dc.Clear();
dc.DrawBitmap(Scale(relationimage),leftBorder,upperBorder,true);
dc.DrawBitmap(Scale(himage),leftBorder,upperBorder,true);

return aBitmap;