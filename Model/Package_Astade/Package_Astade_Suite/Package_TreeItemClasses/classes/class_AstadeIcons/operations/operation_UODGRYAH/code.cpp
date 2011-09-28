//~~ wxBitmap GetOverridesIcon() [AstadeIcons] ~~
#include "overrides_png.h"

wxMemoryInputStream istream(overrides_png, sizeof overrides_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);