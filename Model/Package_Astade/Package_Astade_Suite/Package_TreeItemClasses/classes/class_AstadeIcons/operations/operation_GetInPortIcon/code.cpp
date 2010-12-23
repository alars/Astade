//~~ wxBitmap GetInPortIcon() [AstadeIcons] ~~
#include "InPort_png.h"

wxMemoryInputStream istream(InPort_png, sizeof InPort_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);