#include "folder_png.h"
#include "component_png.h"

wxMemoryInputStream folderstream(folder_png, sizeof folder_png);
wxImage folderimage(folderstream, wxBITMAP_TYPE_PNG);

wxMemoryInputStream componentstream(component_png, sizeof component_png);
wxImage componentimage(componentstream, wxBITMAP_TYPE_PNG);

wxBitmap aBitmap(imageWidth,imageHeight);
wxMemoryDC dc;
dc.SelectObject(aBitmap);
dc.SetBrush(*wxWHITE_BRUSH);

dc.Clear();
dc.DrawBitmap(Scale(folderimage),0,0,true);
dc.DrawBitmap(Scale(componentimage),0,0,true);

return aBitmap;