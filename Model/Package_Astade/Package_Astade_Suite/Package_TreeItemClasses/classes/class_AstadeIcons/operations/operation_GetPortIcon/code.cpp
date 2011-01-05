//~~ wxBitmap GetInPortIcon() [AstadeIcons] ~~
#include "port_png.h"

wxMemoryInputStream istream(port_png, sizeof port_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);