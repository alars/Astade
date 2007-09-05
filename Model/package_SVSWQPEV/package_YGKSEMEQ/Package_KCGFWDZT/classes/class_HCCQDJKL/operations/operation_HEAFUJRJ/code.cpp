#include "folder_png.h"
#include "component_png.h"

wxMemoryInputStream folderstream(folder_png, sizeof folder_png);
wxImage folderimage(folderstream, wxBITMAP_TYPE_PNG);

wxMemoryInputStream componentstream(component_png, sizeof component_png);
wxImage componentimage(componentstream, wxBITMAP_TYPE_PNG);

wxBitmap aBitmap(78,60);
wxMemoryDC dc;
dc.SelectObject(aBitmap);
dc.SetBrush(*wxWHITE_BRUSH);

dc.Clear();
dc.DrawBitmap(wxBitmap(folderimage.Scale(3 * folderimage.GetWidth(), 3 * folderimage.GetHeight(),wxIMAGE_QUALITY_HIGH)),0,0,true);
dc.DrawBitmap(wxBitmap(componentimage.Scale(3 * componentimage.GetWidth(), 3 * componentimage.GetHeight(),wxIMAGE_QUALITY_HIGH)),0,0,true);

return aBitmap;