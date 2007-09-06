#include "operation_png.h"
#include "constructor_png.h"
#include "destructor_png.h"

#include "public_png.h"
#include "protected_png.h"
#include "private_png.h"

#include "static_png.h"
#include "virtual_png.h"
#include "abstract_png.h"

#include "const_png.h"

wxMemoryInputStream operationstream(operation_png, sizeof operation_png);
wxImage operationimage(operationstream, wxBITMAP_TYPE_PNG);

wxMemoryInputStream constructorstream(constructor_png, sizeof constructor_png);
wxImage constructorimage(constructorstream, wxBITMAP_TYPE_PNG);

wxMemoryInputStream destructorstream(destructor_png, sizeof destructor_png);
wxImage destructorimage(destructorstream, wxBITMAP_TYPE_PNG);

wxMemoryInputStream publicstream(public_png, sizeof public_png);
wxImage publicimage(publicstream, wxBITMAP_TYPE_PNG);

wxMemoryInputStream protectedstream(protected_png, sizeof protected_png);
wxImage protectedimage(protectedstream, wxBITMAP_TYPE_PNG);

wxMemoryInputStream privatestream(private_png, sizeof private_png);
wxImage privateimage(privatestream, wxBITMAP_TYPE_PNG);

wxMemoryInputStream staticstream(static_png, sizeof static_png);
wxImage staticimage(staticstream, wxBITMAP_TYPE_PNG);

wxMemoryInputStream virtualstream(virtual_png, sizeof virtual_png);
wxImage virtualimage(virtualstream, wxBITMAP_TYPE_PNG);

wxMemoryInputStream abstractstream(abstract_png, sizeof abstract_png);
wxImage abstractimage(abstractstream, wxBITMAP_TYPE_PNG);

wxMemoryInputStream conststream(const_png, sizeof const_png);
wxImage constimage(conststream, wxBITMAP_TYPE_PNG);

wxBitmap aBitmap(imageWidth,imageHeight);
wxMemoryDC dc;
dc.SelectObject(aBitmap);
dc.SetBrush(*wxWHITE_BRUSH);

dc.Clear();
dc.DrawBitmap(Scale(operationimage),0,0,true);
if (operationType == 1)
	dc.DrawBitmap(Scale(destructorimage),0,0,true);
if (operationType == 2)
	dc.DrawBitmap(Scale(constructorimage),0,0,true);

if (visibility == 0)
	dc.DrawBitmap(Scale(publicimage),0,0,true);
if (visibility == 1)
	dc.DrawBitmap(Scale(protectedimage),0,0,true);
if (visibility == 2)
	dc.DrawBitmap(Scale(privateimage),0,0,true);

if (scope == 1)
	dc.DrawBitmap(Scale(staticimage),0,0,true);
if (scope == 2)
	dc.DrawBitmap(Scale(virtualimage),0,0,true);
if (scope == 3)
	dc.DrawBitmap(Scale(abstractimage),0,0,true);

if (isConst)
	dc.DrawBitmap(Scale(constimage),0,0,true);


return aBitmap;