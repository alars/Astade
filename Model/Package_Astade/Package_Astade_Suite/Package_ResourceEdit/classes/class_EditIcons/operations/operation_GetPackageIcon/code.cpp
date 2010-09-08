//~~ wxBitmap GetPackageIcon(bool isNamespace) [EditIcons] ~~
#include "package_png.h"
#include "namespace_png.h"

wxMemoryInputStream istream(package_png, sizeof package_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

wxBitmap aBitmap(imageWidth,imageHeight);
wxMemoryDC dc;
dc.SelectObject(aBitmap);
dc.SetBrush(*wxWHITE_BRUSH);

dc.Clear();
dc.DrawBitmap(Scale(myimage),leftBorder,upperBorder,true);

if (isNamespace)
{
    wxMemoryInputStream istream2(namespace_png, sizeof namespace_png);
    wxImage aImage(istream2, wxBITMAP_TYPE_PNG);
    dc.DrawBitmap(Scale(aImage),leftBorder,upperBorder,true);
}


return aBitmap;