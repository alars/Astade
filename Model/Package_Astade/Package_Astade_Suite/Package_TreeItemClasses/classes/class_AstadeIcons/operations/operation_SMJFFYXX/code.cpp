//~~ wxBitmap GetPHPIcon() [AstadeIcons] ~~
#include "php_png.h"

wxMemoryInputStream istream(php_png, sizeof php_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);