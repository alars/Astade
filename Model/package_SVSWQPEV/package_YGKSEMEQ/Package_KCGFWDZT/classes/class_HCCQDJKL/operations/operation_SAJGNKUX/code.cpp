#include "attribute_png.h"

#include "public_png.h"
#include "protected_png.h"
#include "private_png.h"

#include "static_png.h"
#include "const_png.h"

wxMemoryInputStream attributestream(attribute_png, sizeof attribute_png);
wxImage attributeimage(attributestream, wxBITMAP_TYPE_PNG);

wxMemoryInputStream publicstream(public_png, sizeof public_png);
wxImage publicimage(publicstream, wxBITMAP_TYPE_PNG);

wxMemoryInputStream protectedstream(protected_png, sizeof protected_png);
wxImage protectedimage(protectedstream, wxBITMAP_TYPE_PNG);

wxMemoryInputStream privatestream(private_png, sizeof private_png);
wxImage privateimage(privatestream, wxBITMAP_TYPE_PNG);

wxMemoryInputStream staticstream(static_png, sizeof static_png);
wxImage staticimage(staticstream, wxBITMAP_TYPE_PNG);

wxMemoryInputStream conststream(const_png, sizeof const_png);
wxImage constimage(conststream, wxBITMAP_TYPE_PNG);

wxBitmap aBitmap(imageWidth,imageHeight);
wxMemoryDC dc;
dc.SelectObject(aBitmap);
dc.SetBrush(*wxWHITE_BRUSH);

dc.Clear();
dc.DrawBitmap(Scale(attributeimage),0,0,true);

if (visibility == 0)
	dc.DrawBitmap(Scale(publicimage),0,0,true);
if (visibility == 1)
	dc.DrawBitmap(Scale(protectedimage),0,0,true);
if (visibility == 2)
	dc.DrawBitmap(Scale(privateimage),0,0,true);

if (scope == 1)
	dc.DrawBitmap(Scale(staticimage),0,0,true);

if (isConst)
	dc.DrawBitmap(Scale(constimage),0,0,true);


return aBitmap;