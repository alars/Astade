#include "class_png.h"
#include "lib_png.h"

wxMemoryInputStream classstream(class_png, sizeof class_png);
wxImage classimage(classstream, wxBITMAP_TYPE_PNG);

wxMemoryInputStream libstream(lib_png, sizeof lib_png);
wxImage libimage(libstream, wxBITMAP_TYPE_PNG);

wxBitmap aBitmap(imageWidth,imageHeight);
wxMemoryDC dc;
dc.SelectObject(aBitmap);
dc.SetBrush(*wxWHITE_BRUSH);

dc.Clear();
dc.DrawBitmap(Scale(classimage),leftBorder,upperBorder,true);
dc.DrawBitmap(Scale(libimage),leftBorder,upperBorder,true);

return aBitmap;