#include "relation_png.h"
#include "cpp_png.h"

wxMemoryInputStream relationstream(relation_png, sizeof relation_png);
wxImage relationimage(relationstream, wxBITMAP_TYPE_PNG);

wxMemoryInputStream cppstream(cpp_png, sizeof cpp_png);
wxImage cppimage(cppstream, wxBITMAP_TYPE_PNG);

wxBitmap aBitmap(imageWidth,imageHeight);
wxMemoryDC dc;
dc.SelectObject(aBitmap);
dc.SetBrush(*wxWHITE_BRUSH);

dc.Clear();
dc.DrawBitmap(Scale(relationimage),leftBorder,upperBorder,true);
dc.DrawBitmap(Scale(cppimage),leftBorder,upperBorder,true);

return aBitmap;