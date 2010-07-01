//~~ wxBitmap GetCppIcon() [AstadeIcons] ~~
#include "cpp_png.h"

wxMemoryInputStream istream(cpp_png, sizeof cpp_png);
wxImage myimage(istream, wxBITMAP_TYPE_PNG);

return wxBitmap(myimage);