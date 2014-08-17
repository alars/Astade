//~~ wxBitmap GetIfIcon() [AstadeIcons] ~~
#include "if_png.h"

wxMemoryInputStream istream(if_png, sizeof if_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);