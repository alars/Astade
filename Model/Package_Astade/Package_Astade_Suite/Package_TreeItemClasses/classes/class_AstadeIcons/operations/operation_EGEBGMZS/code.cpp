//~~ wxBitmap GetEmptyIcon() [AstadeIcons] ~~
#include "empty_png.h"

wxMemoryInputStream istream(empty_png, sizeof empty_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);