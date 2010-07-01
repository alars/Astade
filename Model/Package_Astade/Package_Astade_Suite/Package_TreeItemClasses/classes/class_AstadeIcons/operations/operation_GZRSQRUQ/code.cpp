//~~ wxBitmap GetTxtIcon() [AstadeIcons] ~~
#include "txt_png.h"

wxMemoryInputStream istream(txt_png, sizeof txt_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);