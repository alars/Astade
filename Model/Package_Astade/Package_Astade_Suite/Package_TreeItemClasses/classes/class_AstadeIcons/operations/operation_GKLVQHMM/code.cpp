//~~ wxBitmap GetPortsIcon() [AstadeIcons] ~~
#include "ports_png.h"

wxMemoryInputStream istream(ports_png, sizeof ports_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);