#include "component_png.h"

wxMemoryInputStream istream(component_png, sizeof component_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

wxBitmap aBitmap(78,60);
wxMemoryDC dc;
dc.SelectObject(aBitmap);
dc.SetBrush(*wxWHITE_BRUSH);

dc.Clear();
dc.DrawBitmap(wxBitmap(myimage.Scale(3 * myimage.GetWidth(), 3 * myimage.GetHeight(),wxIMAGE_QUALITY_HIGH)),0,0,true);

return aBitmap;