#include "component_png.h"
#include "framework_png.h"

wxMemoryInputStream istream(component_png, sizeof component_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

wxMemoryInputStream framework_istream(framework_png, sizeof framework_png);
wxImage myframeworkImage(framework_istream, wxBITMAP_TYPE_PNG);

wxBitmap aBitmap(imageWidth,imageHeight);
wxMemoryDC dc;
dc.SelectObject(aBitmap);
dc.SetBrush(*wxWHITE_BRUSH);

dc.Clear();
dc.DrawBitmap(Scale(myimage),leftBorder,upperBorder,true);

if (useFramework)
	dc.DrawBitmap(Scale(myframeworkImage),leftBorder,upperBorder,true);
	
return aBitmap;
