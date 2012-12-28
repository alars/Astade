//~~ wxBitmap GetChangedIcon() [AstadeIcons] ~~
#include "changed_png.h"

wxMemoryInputStream istream(changed_png, sizeof changed_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);