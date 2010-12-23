//~~ wxBitmap GetDelegateIcon() [AstadeIcons] ~~
#include "delegate_png.h"

wxMemoryInputStream istream(delegate_png, sizeof delegate_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);