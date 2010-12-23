//~~ wxBitmap GetManualclassIcon() [EditIcons] ~~
#include "class_png.h"
#include "manual_png.h"

wxMemoryInputStream classstream(class_png, sizeof class_png);
wxImage classimage(classstream, wxBITMAP_TYPE_PNG);

wxMemoryInputStream manualstream(manual_png, sizeof manual_png);
wxImage manualimage(manualstream, wxBITMAP_TYPE_PNG);

wxBitmap aBitmap(imageWidth,imageHeight);
wxMemoryDC dc;
dc.SelectObject(aBitmap);
dc.SetBrush(*wxWHITE_BRUSH);

dc.Clear();
dc.DrawBitmap(Scale(classimage),leftBorder,upperBorder,true);
dc.DrawBitmap(Scale(manualimage),leftBorder,upperBorder,true);

return aBitmap;
