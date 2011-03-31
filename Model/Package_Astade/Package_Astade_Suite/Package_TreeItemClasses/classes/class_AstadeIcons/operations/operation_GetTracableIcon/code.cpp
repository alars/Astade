//~~ wxBitmap GetTracableIcon() [AstadeIcons] ~~
#include "tracable_png.h"

wxMemoryInputStream istream(tracable_png, sizeof tracable_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);
