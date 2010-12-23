//~~ wxBitmap GetOutPortIcon() [AstadeIcons] ~~
#include "OutPort_png.h"

wxMemoryInputStream istream(OutPort_png, sizeof OutPort_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);