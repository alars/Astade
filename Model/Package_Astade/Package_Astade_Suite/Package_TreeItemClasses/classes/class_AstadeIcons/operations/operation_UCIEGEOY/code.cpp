//~~ wxBitmap GetConnectionIcon() [AstadeIcons] ~~
#include "connection_png.h"

wxMemoryInputStream istream(connection_png, sizeof connection_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);