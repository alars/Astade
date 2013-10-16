//~~ wxBitmap GetTerminateIcon() [AstadeIcons] ~~
#include "terminate_png.h"

wxMemoryInputStream istream(terminate_png, sizeof terminate_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);